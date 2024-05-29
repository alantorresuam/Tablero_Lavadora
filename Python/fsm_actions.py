"""This module holds the actions associated to this project
"""

from fsm import FSM

def init_fsm(fsm: FSM, event: dict[str, int]) -> None:
    """Set the transition rules of the FSM to be implemented

    Args:
        fsm (FSM): A non-initialized finite state machine 
    """
    fsm.set_transition_rule(0, event['encender'], 1)
    fsm.set_transition_rule(1, event['apagar'], 0)
    fsm.set_transition_rule(1, event['lavar'], 2)
    fsm.set_transition_rule(1, event['enjuagar'], 3)
    fsm.set_transition_rule(1, event['centrifugar'], 4)
    fsm.set_transition_rule(2, event['apagar'], 0)
    fsm.set_transition_rule(2, event['lavado fin'], 1)
    fsm.set_transition_rule(2, event['lavar y enjuagar'], 3)
    fsm.set_transition_rule(2, event['lavar y centrifugar'], 4)
    fsm.set_transition_rule(2, event['pausar'], 5)
    fsm.set_transition_rule(3, event['apagar'], 0)
    fsm.set_transition_rule(3, event['enjuagado fin'], 1)
    fsm.set_transition_rule(3, event['centrifugar'], 4)
    fsm.set_transition_rule(3, event['pausar'], 5)
    fsm.set_transition_rule(4, event['apagar'], 0)
    fsm.set_transition_rule(4, event['centrifugado fin'], 1)
    fsm.set_transition_rule(4, event['pausar'], 5)
    fsm.set_transition_rule(5, event['apagar'], 0)
    fsm.set_transition_rule(5, event['lavando'], 2)
    fsm.set_transition_rule(5, event['enjuagando'], 3)
    fsm.set_transition_rule(5, event['centrifugando'], 4)