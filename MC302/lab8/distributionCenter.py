#Fabio Tadashi Kaneiwa Kubo 145979
import re

class Cidade(object):
  def __init__(self, id, capacidade, nome):
    self.id = id
    self.capacidade = capacidade
    self.nome = nome

class Distancia(object):
  def __init__(self, cidadeA, cidadeB, distancia):
    self.cidadeA = cidadeA
    self.cidadeB = cidadeB
    self.distancia = distancia

cidades = []
matrizDistancias = [[[]]]

def carregaInformacao():
  arqEntrada = open('distancias.txt')
  qtdCidade = arqEntrada.readline()
 
  for i in range(0, qtdCidade):
    linha = arqEntrada.readline()
    listAux = re.findAll('[^\s]+', linha)
    cidades.append(Cidade(listAux[0], listAux[1], listAux[2]))

  arqEntrada.readline(); # ignora o -1-1 xx
  pararLeitura = False;
  while not pararLeitura:
    linha = arqEntrada.readline()
    if linha == '-1-1-1':
      pararLeitura = True
    else:
      listAux = re.findAll('[^\s]+', linha)
      matrizDistancias[0][list[0]][list[1]] = list[2]

def getCustoDistribuicao():
  

   
#Metodo que calcula a menor distancia entre cidades baseado no algoritmo de Floyd-Warshall
def calculaDistancia():
  for k in range(1, len(cidades)):
     for i in range(1, len(cidades)):
        for j in range(1, len(cidades)):
           dist[k][i][j] = min(dist[k-1][i][j], dist[k-1][i][k] + dist[k-1][k][j])

def 



