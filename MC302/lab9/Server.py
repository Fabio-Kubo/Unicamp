#Fabio Tadashi Kaneiwa Kubo 145979
import re, sys

from SimpleXMLRPCServer import SimpleXMLRPCServer

#classe que contem as informacoes de uma cidade
class Cidade(object):
	def __init__(self, id, capacidade, nome):
		self.id = id 
		self.capacidade = capacidade
		self.nome = nome
		self.custoDistribuicao = 0

cidades = [] #lista com as cidades
arqEntrada = open('distancias.txt')

#metodo que carrega as cidades numa lista
def carregaCidades(arqEntrada):

	qtdCidade = int(arqEntrada.readline())
	for i in range(0, qtdCidade):
		linha = arqEntrada.readline()
		listAux = re.findall('[^\s]+', linha)
		cidades.append(Cidade(int(listAux[0]), int(listAux[1]), listAux[2]))

#metodo que carrega as distancias entre as cidades
def carregaDistancias(arqEntrada, qtdCidade): 
	matrizDistancias = [[9999 for i in range(0, qtdCidade)] for j in range(0, qtdCidade)]
	pararLeitura = False
	arqEntrada.readline() # ignora o -1-1 xx
	
	while not pararLeitura:
		linha = arqEntrada.readline()
		listAux = re.findall('[^\s]+', linha)

		if listAux[0] == '-1':
			pararLeitura = True
		else:
			#como o grafo eh nao direcional, inclui-se o caminho i -> j e j -> i
			matrizDistancias[int(listAux[0]) - 1][int(listAux[1]) - 1] = int(listAux[2])
			matrizDistancias[int(listAux[1]) - 1][int(listAux[0]) - 1] = int(listAux[2])

	return matrizDistancias

#metodo baseado no algoritmo de Floyd-Warshall, que calcula as menores distancias entre os vertices(cidades)
def calculaMenorCaminho(dist, qtdCidade):
	for k in range(0, qtdCidade):
		for i in range(0, qtdCidade):
			for j in range(0, qtdCidade):
				dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] )

#metodo que calcula o custo de distribuicao das cidades
def calculaCustoDistribuicao(cidades, matrizDistancias):
	for cidade in cidades:
		custo = 0
		for cidadeB in cidades:
			if cidade.id != cidadeB.id:
				custo = custo + matrizDistancias[cidade.id - 1][cidadeB.id - 1] * cidadeB.capacidade
		cidade.custoDistribuicao = custo


#Metodo usado para verificacao basica da conectividade..
def ping():
	return True

#Metodo que retorna um string com o ra do aluno responsavel pelo servidor
def ra():
	return "145979"

#Metodo que retorna um string com o nome do aluno responsavel pelo servidor
def nome():
	return "Fabio Tadashi Kaneiwa Kubo"

#Metodo que retorna a cidade de acordo com seu nome. Caso nao encontre a cidade, retorna-se None
def getCidade(nmCidade):

	cidade = None
	for c in cidades:
		if(nmCidade == c.nome):
			cidade = c
			break
	return cidade

#Metodo que retorna o nome da cidade mais proxima da cidade passada por parametro
#Caso a cidade passada como parametro nao exista, retorna "???".
def maisProxima(nmCidade):

	cidadeReferencia = getCidade(nmCidade)

	if cidadeReferencia is None:
		return "???"

	menorDistancia = sys.maxint
	cidadeMaisProxima = 0
	for i in range(0, len(cidades)):

		#ignora a cidade referencia
		if(cidadeReferencia.id -1 != i):
			if(matrizDistancias[cidadeReferencia.id - 1][i] < menorDistancia):
				menorDistancia = matrizDistancias[cidadeReferencia.id - 1][i]
				cidadeMaisProxima = i

	return cidades[cidadeMaisProxima].nome

#Metodo que retorna o nome da cidade mais distante da cidade passada por parametro
#Caso a cidade passada como parametro nao exista, retorna "???".
def maisDistante(nmCidade):

	cidadeReferencia = getCidade(nmCidade)
	if cidadeReferencia is None:
		return "???"

	maiorDistancia = 0
	cidadeMaisDistante = 0
	for i in range(0, len(cidades)):

		#ignora a cidade referencia
		if(cidadeReferencia.id -1 != i):
			if(matrizDistancias[cidadeReferencia.id - 1][i] > maiorDistancia):
				maiorDistancia = matrizDistancias[cidadeReferencia.id - 1][i]
				cidadeMaisDistante = i

	return cidades[cidadeMaisDistante].nome

#Metodo que retorna a lista com os nomes das cidades a
#que se pode chegar por rodovia a partir de uma cidade origem, cujo nome eh passado como
#parametro, e cuja distancia eh menor que um certo limite (inteiro), em quilometros, passado como
#parametro. Deve retornar None se a cidade origem nao existir.
def listaNumLimite(nmCidadeOrigem, limite):

	cidadeReferencia = getCidade(nmCidadeOrigem)
	if cidadeReferencia is None:
		return None

	retornoLista = []

	for i in range(0, len(cidades)):

		#ignora a cidade referencia
		if(cidadeReferencia.id -1 != i):
			if(matrizDistancias[cidadeReferencia.id - 1][i] <= limite):
				retornoLista.append(cidades[i].nome)

	return retornoLista

carregaCidades(arqEntrada) #monta dicionario que guarda as cidades (chave = id)
matrizDistancias = carregaDistancias(arqEntrada, len(cidades)) # carrega as distancias
calculaMenorCaminho(matrizDistancias, len(cidades))
calculaCustoDistribuicao(cidades, matrizDistancias)

servidor = SimpleXMLRPCServer(('xaveco.lab.ic.unicamp.br', 9001), logRequests=True, allow_none=True)

# registro das funcoes 'publicadas' pelo servidor
# (toda funcao publicada deve ser registrada)
print 'registrando as funcoes...'
servidor.register_function(ping)
servidor.register_function(ra)
servidor.register_function(nome)
servidor.register_function(maisProxima)
servidor.register_function(maisDistante)
servidor.register_function(listaNumLimite)

try:
    print 'Para encerrar digite Control-C '
    servidor.serve_forever()
except KeyboardInterrupt:
    print 'Encerrando o servidor'
