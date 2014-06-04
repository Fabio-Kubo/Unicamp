import xmlrpclib

def main():
    cc = xmlrpclib.ServerProxy('http://localhost:9001')
    print "ping:",cc.ping()
    print "ra:",cc.ra()
    print "nome:",cc.nome()
    print "cidade mais proxima",cc.maisProxima("Sorocaba")
    print "cidade mais distante",cc.maisDistante("Piracicaba")
    print "lista numero limite",cc.listaNumLimite("Capao_Bonito",60)

    cc = xmlrpclib.ServerProxy('http://xaveco.lab.ic.unicamp.br:9174')
    print "ping:",cc.ping()
    print "ra:",cc.ra()
    print "nome:",cc.nome()
    print "cidade mais proxima",cc.maisProxima("Sorocaba")
    print "cidade mais distante",cc.maisDistante("Piracicaba")
    print "lista numero limite",cc.listaNumLimite("Capao_Bonito",60)

    cc = xmlrpclib.ServerProxy('http://xaveco.lab.ic.unicamp.br:9001')
    print "ping:",cc.ping()
    print "ra:",cc.ra()
    print "nome:",cc.nome()
    print "cidade mais proxima",cc.maisProxima("Sorocaba")
    print "cidade mais distante",cc.maisDistante("Piracicaba")
    print "lista numero limite",cc.listaNumLimite("Capao_Bonito",60)

    cc = xmlrpclib.ServerProxy('http://xaveco.lab.ic.unicamp.br:9512')
    print "ping:",cc.ping()
    print "ra:",cc.ra()
    print "nome:",cc.nome()
    print "cidade mais proxima",cc.maisProxima("Sorocaba")
    print "cidade mais distante",cc.maisDistante("Piracicaba")
    print "lista numero limite",cc.listaNumLimite("Capao_Bonito",60)

main()
