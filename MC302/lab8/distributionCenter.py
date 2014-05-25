#Fabio Tadashi Kaneiwa Kubo 145979
import re, sys

class Cidade(object):
	def __init__(self, id, capacidade, nome):
		self.id = id 
		self.capacidade = capacidade
		self.nome = nome
		self.custoDistribuicao = 0

class Distancia(object):
	def __init__(self, cidadeA, cidadeB, distancia):
		self.cidadeA = cidadeA
		self.cidadeB = cidadeB
		self.distancia = distancia

def carregaCidades(arqEntrada):
	cidades = []
	qtdCidade = int(arqEntrada.readline())
	for i in range(0, qtdCidade):
		linha = arqEntrada.readline()
		listAux = re.findall('[^\s]+', linha)
		cidades.append(Cidade(listAux[0], listAux[1], listAux[2]))
	return cidades

def carregaDistancias(arqEntrada, qtdCidade): 
	matrizDistancias = [[[99 for k in range(0, qtdCidade + 1)] for j in range(0, qtdCidade + 1)] for i in range(0, qtdCidade + 1)]
	pararLeitura = False;
	arqEntrada.readline(); # ignora o -1-1 xx
	
	while not pararLeitura:
		linha = arqEntrada.readline()
		listAux = re.findall('[^\s]+', linha)

		if listAux[0] == '-1':
			pararLeitura = True
		else:
			matrizDistancias[0][int(listAux[0])][int(listAux[1])] = int(listAux[2])
			matrizDistancias[0][int(listAux[1])][int(listAux[0])] = int(listAux[2])

	return matrizDistancias

def calculaMenorCaminho(dist, qtdCidade):
	for k in range(1, qtdCidade):
		for i in range(1, qtdCidade):
			for j in range(1, qtdCidade):
				dist[k][i][j] = min(dist[k-1][i][j], dist[k-1][i][k] + dist[k-1][k][j])
	imprimeMatriz(dist)

def calculaCustoDistribuicao(cidades, matrizDistancias):
	for cidade in cidades:
		for cidadeB in cidades:
			if cidade.id != cidadeB.id:
				cidade.custoDistribuicao = matrizDistancias[len(cidades)][int(cidade.id)][int(cidadeB.id)] * cidadeB.capacidade

def imprimiResultado(cidades):
	for cidade in cidades:
		print '[' + cidade.nome + ', '+ cidade.capacidade + ', ' + cidade.custoDistribuicao + ']'
	
	cidades.sort(key=lambda x: x.custoDistribuicao)
	print 'melhor ponto: ' + cidades[0].nome + ' custo: ' + cidades[0].custoDistribuicao
	print 'maior custo: ' + cidades[len(cidades) - 1].nome + ' custo: ' + cidades[len(cidades) - 1].custoDistribuicao

def main():
	cidades = []
	arqEntrada = open('distancias.txt')
	cidades = carregaCidades(arqEntrada) #monta dicionario que guarda as cidades (chave = id)
	matrizDistancias = carregaDistancias(arqEntrada, len(cidades)) # carrega as distancias
	calculaMenorCaminho(matrizDistancias, len(cidades))
	#calculaCustoDistribuicao(cidades, matrizDistancias)
	#imprimiResultado(cidades)

def imprimeMatriz(matriz):
	n = 31
	for k in range(0,1):
		for i in range(0, n):
			for j in range(0, n):
				print matriz[n][j][i],
			print ' '

main()
