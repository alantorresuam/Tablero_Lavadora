from fsm import FSM
from Blynk import WasherPeripheral

ev = {
    'encender' : 0, 
    'apagar' : 1, 
    'enjuagar' : 2, 
    'centrifugar' : 3, 
    'lavado fin' : 4,
    'lavar y enjuagar' : 5,
    'lavar y centrifugar' : 6,
    'pausar' : 7,       
    'enjuagado fin' : 8,    
    'centrifugado fin' : 9, 
    'lavando' : 10,     
    'enjuagando': 11,
    'centrifugando': 12,
    'lavar': 13
    }

fsm: FSM = FSM()

washerPeripheral: WasherPeripheral = WasherPeripheral()