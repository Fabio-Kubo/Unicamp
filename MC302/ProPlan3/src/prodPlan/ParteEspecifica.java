package prodPlan;

import java.util.HashMap;

public class ParteEspecifica extends Parte {

	private HashMap<String, String> caracteristicas;

	public ParteEspecifica(int cod, String nome, String descricao, float valor) {
		super(cod, nome, descricao, valor);
		this.caracteristicas = new HashMap<String, String>();
	}

	public String caracteristica(String nome) {

		return this.caracteristicas.get(nome);
	}

	public void agregaCaracteristica(String nome, String conteudo)
			throws Exception {
		
		if(nome == null || conteudo == null)
			throw new Exception("Parametros invalidos");
		
		if (this.caracteristicas.containsKey(nome)) {
			throw new Exception("Característica já existente");
		}

		this.caracteristicas.put(nome, conteudo);
	}
}
