#Fabio Tadashi Kaneiwa Kubo 145979
import re

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
  cidades = {}
  qtdCidade = int(arqEntrada.readline())
  for i in range(0, qtdCidade):
  	linha = arqEntrada.readline()
  	listAux = re.findall('[^\s]+', linha)
  	cidades[listAux[0]] = Cidade(listAux[0], listAux[1], listAux[2])
  return cidades

def carregaDistancias(arqEntrada, qtdCidade): 
  matrizDistancias = [[[10000 for k in range(0, qtdCidade + 1)] for j in range(0, qtdCidade + 1)] for i in range(0, qtdCidade + 1)]
  pararLeitura = False;
  arqEntrada.readline(); # ignora o -1-1 xx
  
  while not pararLeitura:
    linha = arqEntrada.readline()
    listAux = re.findall('[^\s]+', linha)

    if listAux[0] == '-1':
      pararLeitura = True
    else:
      matrizDistancias[0][int(listAux[0])][int(listAux[1])] = int(listAux[2])

  return matrizDistancias

def calculaMenorCaminho(dist, qtdCidade):
  for k in range(1, qtdCidade):
    for i in range(1, qtdCidade):
	  for j in range(1, qtdCidade):
	    dist[k][i][j] = min(dist[k-1][i][j], dist[k-1][i][k] + dist[k-1][k][j])

def calculaCustoDistribuicao(cidades, matrizDistancias):
  for cidade in cidades:
  	for cidadeB in cidades:
  	  if cidade != cidadeB:
		cidade.custoDistribuicao = matrizDistancias[len(cidades)][((Cidade)cidade).id][cidadeB.id] * cidadeB.capacidade

def imprimeMatriz(matriz):
  n = 31
  for k in range(0, n):
  	for i in range(0, n):
  	  for j in range(0, n): 
  	  	print matriz[k][j][i],
 	  print ' '

def main():

  cidades = {}	
  arqEntrada = open('distancias.txt')
  cidades = carregaCidades(arqEntrada) #monta dicionario que guarda as cidades (chave = id)
  matrizDistancias = carregaDistancias(arqEntrada, len(cidades)) # carrega as distancias
  calculaMenorCaminho(matrizDistancias, len(cidades))
  calculaCustoDistribuicao(cidades, matrizDistancias)
  imprimeMatriz(matrizDistancias)

main()