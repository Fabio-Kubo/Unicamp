package concorrencia;

public class ExemploQuickSort {
	
	/* lista de nomes a ser ordenada */
	static String[] listaDeNomes1 = { "Luiz" };
	static String[] listaDeNomes2 = { "Jose Luiz", "Jose Carlos" };
	static String[] listaDeNomes3 = { "Jose Luiz", "Jose", "Jose Carlos" };
	
	static String[] listaDeNomes4 = { "Andre", "Luiz", "Vinicius", "Geraldo",
			"Isabela", "Fernando", "Marcelo", "Ricardo", "Danilo", "Flavio",
			"Gustavo", "Ivanildo", "Jose", "Leandro", "Candido", "Jose Carlos",
			"Carlos Jose", "Jose Luiz", "Jose Pedro", "Joao Pedro",
			"Jose Roberto", "Romao", "Ramon", "Marcos", "Maicol", "Michel",
			"Michelle", "Rodrigo", "Sergio", "Victor", "Vitor", "Vitorio",
			"Humberto", "Rafael", "Fabio", "Fabiano", "Fabiana", "Fabiola",
			"Davi", "Giordano", "Mauricio", "Thiago", "Thomaz", "Tomas",
			"Alexandre", "Henrique", "Aline", "Angelo", "Bruna", "Bruno",
			"Dario", "Evandro", "Felipe", "Izis", "Tiago", "Thiago", "Lucas",
			"Mateus", "Vera Lucia", "Regina", "Cecilia", "Rosana", "Rosiane",
			"Renato", "Renata", "Andreia", "Maria Carolina", "Maria Leticia",
			"Luiz Antonio", "Luiz Ignacio", "Luiz Carlos", "Pedro Luiz",
			"Pedro", "Alberto", "Marco Antonio", "Marco Aurelio", "Marco",
			"Augusto", "Luiz Augusto", "Maria Cecilia", "Alice", "Alice Maria",
			"Maria Jose", "Jose Maria", "Joao Carlos", "Joao Luiz",
			"Joao Marcos", "Joana", "Heraldo", "Johnny", "Gladys", "Patrick",
			"Steve", "Samuel", "Willian", "Guilherme", "Severino", "Mario",
			"Aurelio", "Jose Roberto", "Cristina", "Maria Cristina", "Lorella",
			"Marta", "Marcia", "Edilene", "Daniel", "Edson", "Francisco",
			"Candido", "Antonio Candido", "Eulalia", "Nestor", "Ernesto",
			"Adoniram", "Edvaldo", "Evair", "Juliano", "Ariovaldo", "Osvaldo",
			"Jose Osvaldo", "Renato", "Jose Renato" };

	/**
	 * Escreve a lista de nomes na saída padrão
	 */
	public static void print() {
		for (int i = 0; i < listaDeNomes4.length; i++)
			System.out.println(listaDeNomes4[i]);
	}

	/**
	 * @param args
	 * @throws InterruptedException
	 */
	public static void main(String[] args) throws InterruptedException {
		Quick.sort(listaDeNomes4);
		print();
	}
}
