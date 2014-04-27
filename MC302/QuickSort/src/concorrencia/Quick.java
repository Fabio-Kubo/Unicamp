package concorrencia;

/**
 * @author Fabio Tadashi Kaneiwa Kubo ra:145979
 * QuickSort com Threads
 */

public class Quick implements Runnable {

	private String[] vetor;
	private int indiceInicio;
	private int indiceFim;

	/**
	 * Construtor
	 * v - vetor de Strings
	 * iInicio - indice do inicio do vetor
	 * iFim - indice do fim do vetor
	 */
	public Quick(String[] v, int iInicio, int iFim) {
		this.vetor = v;
		this.indiceInicio = iInicio;
		this.indiceFim = iFim;
	}
	
	/**
	 * Metodo que ordena um vetor de Strings
	 */
	public static void sort(String[] lista) throws InterruptedException {
		Thread tQuick = new Thread(new Quick(lista, 0, lista.length - 1));
		tQuick.start();
		tQuick.join();
	}
	
	/**
	 * Metodo que realiza o partition do quickSort
	 */
	private int partition(String[] lista, int iInicio, int iFim) {
		String pivo;
		int iPivo;
		pivo = lista[iInicio];
		iPivo = iInicio;

		for (int i = iInicio + 1; i <= iFim; i++) {
			if (lista[i].compareTo(pivo) < 0) {
				lista[iPivo] = lista[i];
				lista[i] = lista[iPivo + 1];
				iPivo++;
			}
		}
		lista[iPivo] = pivo;
		return iPivo;
	}
	
	/**
	 * Metodo que realiza uma particao e cria duas threads para ordenar as duas 
	 * partes criadas pelo partition
	 */
	@Override
	public void run() {
		int meio;

		if (this.indiceInicio < this.indiceFim) {
			meio = partition(this.vetor, this.indiceInicio, this.indiceFim);

			Thread q1 = new Thread(new Quick(this.vetor, this.indiceInicio,
					meio));
			Thread q2 = new Thread(new Quick(this.vetor, meio + 1,
					this.indiceFim));

			q1.run();
			q2.run();			
			
			try {
				q1.join();
				q2.join();
			} catch (InterruptedException e) {
				System.out.print(e.getMessage());
				e.printStackTrace();
			}
		}
	}

}
