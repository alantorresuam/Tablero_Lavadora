class FSM:
    """This class implements a deterministic finite state machine working with Raspberry Pico W interrupts as events
    """
    def __init__(self, initial_state: int = 0) -> None:
        """ Initializes the finite state machine

        Args:
            initial_state (int): the code of the initial state (default = 0)
        """
        self.__current_state = initial_state
        self.__transitions : dict[tuple[int, int], int] = {}

    def get_current_state(self) -> int:
        """ Returns the current state of the FSM

        Returns:
            int: the code of the current state
        """
        return self.__current_state
    
    def set_transition_rule(self, current_state: int, event_number: int, next_state: int) -> None:
        """Set the transition rules the FSM obeys

        Args:
            current_state (int): the code of the current state
            event_number (str): the name of the interrupt that yields the state change
            next_state (int): the code of the next state
        """
        self.__transitions[(current_state, event_number)] = next_state

    def get_next_state(self, current_state: int, event_number: int) -> int:
        """ Returns the code of the next state

        Args:
            current_state (int): the code of the current state
            event (str): the kind of interrupt producing the change of state

        Returns:
            int: The code of the next state
        """
        return self.__transitions[(current_state, event_number)]
    
    def compute_next_state(self, event_number: int) -> None:
        """ Updates the code of the current state according to the code of the next state

        Args:
            event (str): the kind of interrupt producing the change of state

        """
        try:
            self.__current_state = self.__transitions[(self.__current_state, event_number)]
        except KeyError:
            print(f'Damn it! [{self.__current_state}, {event_number}]')
            self.__current_state = -1
