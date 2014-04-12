package processaDadosAluno;

import java.io.*;
import java.util.*;
import java.util.Map.Entry;

public class ProcessaDados {

	public static void main(String[] args) {

		try {
			// instancia um objeto responsavel pela leitura
			BufferedReader leitor = new BufferedReader(new FileReader(
					"alunos.csv"));

			String linha;
			HashMap<String, Integer> nomeQtd = new HashMap<String, Integer>();
			HashMap<String, Integer> rgQtd = new HashMap<String, Integer>();
			HashMap<String, Integer> cursoQtd = new HashMap<String, Integer>();
			linha = leitor.readLine(); // descarta a primeira linha

			// Excecuta o procedimento enquanto houver coisa pra ler
			while (leitor.ready()) {
				linha = leitor.readLine();
				String[] l = linha.split(";");

				atualizaContadorRg(rgQtd, l[PropriedadeAluno.RG.getCode()]);
				atualizaContadorNome(nomeQtd,
						l[PropriedadeAluno.NOME.getCode()]);
				atualizaContadorCurso(cursoQtd,
						l[PropriedadeAluno.CURSO.getCode()]);
			}

			exibirRelatorioNomesRepetidos(nomeQtd);
			exibirRelatorioRgRepetidos(rgQtd);
			exibirRelatorioQuantidadePorCurso(cursoQtd);

			leitor.close();

		} catch (IOException e) {
			System.out.println("Erro na leitura do arquivo: " + e.getMessage());
		}
	}

	private static void exibirRelatorioQuantidadePorCurso(
			HashMap<String, Integer> cursoQtd) {
		System.out.println("\nQuantidade por curso:");

		for (Entry<String, Integer> entry : cursoQtd.entrySet()) {
			System.out.println(entry.getValue() + " no curso "
					+ entry.getKey());
		}
	}

	private static void exibirRelatorioRgRepetidos(
			HashMap<String, Integer> rgQtd) {
		System.out.println("\nRgs repetidos:");
		for (Entry<String, Integer> entry : rgQtd.entrySet()) {
			if(entry.getValue() > 1) {
				System.out.println(entry.getKey() + " - " + entry.getValue() + " repeticoes");
			}			
		}
	}

	private static void exibirRelatorioNomesRepetidos(
			HashMap<String, Integer> nomeQtd) {
		System.out.println("Nomes repetidos:");
		
		for (Entry<String, Integer> entry : nomeQtd.entrySet()) {
			if(entry.getValue() > 1) {
				System.out.println(entry.getKey() + " - " + entry.getValue() + " repeticoes");
			}
		}
	}

	private static void atualizaContadorCurso(
			HashMap<String, Integer> cursoQtd, String curso) {

		if (cursoQtd.containsKey(curso)) {
			Integer qtd = cursoQtd.get(curso);
			cursoQtd.put(curso, qtd + 1);
		} else {
			cursoQtd.put(curso, 1);
		}
	}

	private static void atualizaContadorNome(HashMap<String, Integer> nomeQtd,
			String nome) {
		if (nomeQtd.containsKey(nome)) {
			Integer qtd = nomeQtd.get(nome);
			nomeQtd.put(nome, qtd + 1);
		} else {
			nomeQtd.put(nome, 1);
		}
	}

	private static void atualizaContadorRg(HashMap<String, Integer> rgQtd,
			String rg) {
		if (rgQtd.containsKey(rg)) {
			Integer qtd = rgQtd.get(rg);
			rgQtd.put(rg, qtd + 1);
		} else {
			rgQtd.put(rg, 1);
		}
	}

}
