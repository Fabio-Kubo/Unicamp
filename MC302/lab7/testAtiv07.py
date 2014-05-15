import ativ07

def test():
    ativ07.anota('dez/02', 50.4, 494.0)
    ativ07.anota('dez/09', 52.3, 501.0)
    ativ07.anota('dez/16', 49.9, 479.0)
    ativ07.anota('dez/23', 51.1, 509.0)
    ativ07.anota('dez/30', 53.0, 525.0)
    ativ07.anota('jan/06', 50.7, 499.0)
    ativ07.anota('jan/13', 52.1, 519.0)
    ativ07.anota('jan/20', 51.4, 501.0)
    ativ07.anota('jan/26', 52.1, 499.0)
    c,d = ativ07.consMin()
    print 'consumo Minimo:',c,'data:',d
    c,d = ativ07.consMax()
    print 'consumo Maximo:',c,'data:',d
    print 'consumo Medio:',ativ07.consMed()
    print 'quilometragem media dos abastecimentos:',ativ07.kmMed()

test()
    

