#Fabio Tadashi Kaneiwa Kubo 145979
import re

#classe que contem as informacoes de uma cidade
class Cidade(object):
	def __init__(self, id, capacidade, nome):
		self.id = id 
		self.capacidade = capacidade
		self.nome = nome
		self.custoDistribuicao = 0

#metodo que carrega as cidades numa lista
def carregaCidades(arqEntrada):
	cidades = []
	qtdCidade = int(arqEntrada.readline())
	for i in range(0, qtdCidade):
		linha = arqEntrada.readline()
		listAux = re.findall('[^\s]+', linha)
		cidades.append(Cidade(int(listAux[0]), int(listAux[1]), listAux[2]))
	return cidades

#metodo que carrega as distancias entre as cidades
def carregaDistancias(arqEntrada, qtdCidade): 
	matrizDistancias = [[9999 for i in range(0, qtdCidade)] for j in range(0, qtdCidade)]
	pararLeitura = False;
	arqEntrada.readline(); # ignora o -1-1 xx
	
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
				dist[i][j] = min( dist[i][j], dist[i][k] + dist[k][j] );

#metodo que calcula o custo de distribuicao das cidades
def calculaCustoDistribuicao(cidades, matrizDistancias):
	for cidade in cidades:
		custo = 0
		for cidadeB in cidades:
			if cidade.id != cidadeB.id:
				custo = custo + matrizDistancias[cidade.id - 1][cidadeB.id - 1] * cidadeB.capacidade
		cidade.custoDistribuicao = custo

#metodo que imprime o resultado
def imprimiResultado(cidades):
	for cidade in cidades:
		print "['{0}', {1}, {2}]".format(cidade.nome, cidade.capacidade, cidade.custoDistribuicao)
	
	cidades.sort(key=lambda x: x.custoDistribuicao)
	print 'melhor ponto: {0} custo: {1}'.format(cidades[0].nome, cidades[0].custoDistribuicao)
	print 'maior custo: {0} custo: {1}'.format(cidades[len(cidades) - 1].nome, cidades[len(cidades) - 1].custoDistribuicao)

def main():
	cidades = []
	arqEntrada = open('distancias.txt')
	cidades = carregaCidades(arqEntrada) #monta dicionario que guarda as cidades (chave = id)
	matrizDistancias = carregaDistancias(arqEntrada, len(cidades)) # carrega as distancias
	calculaMenorCaminho(matrizDistancias, len(cidades))
	calculaCustoDistribuicao(cidades, matrizDistancias)
	imprimiResultado(cidades)

main()
