package prodPlan;

import java.util.*;
import xserial.*;

public class ParteEspecifica extends Parte {

	private List<Caracteristica> caracteristicas;

	public ParteEspecifica(int cod, String nome, String descricao, float valor) {
		super(cod, nome, descricao, valor);
		this.caracteristicas = new LinkedList<Caracteristica>();
	}

	public ParteEspecifica() {
		this.caracteristicas = new LinkedList<Caracteristica>();
	}

	public String caracteristica(String nome) {

		Caracteristica c = this.getCaracteristica(nome);
		String conteudo = c == null ? null : c.conteudo;

		return conteudo;
	}

	public Caracteristica getCaracteristica(String nome) {

		for (Caracteristica c : this.caracteristicas) {

			if (c.nome == nome)
				return c;
		}

		return null;
	}

	public void agregaCaracteristica(Caracteristica c) throws Exception {

		if (c == null || c.nome == null || c.conteudo == null)
			throw new Exception("Parametros invalidos");

		if (this.getCaracteristica(c.nome) != null) {
			throw new Exception("Característica já existente");
		}

		this.caracteristicas.add(c);
	}

	public void agregaCaracteristica(String nome, String conteudo)
			throws Exception {

		agregaCaracteristica(new Caracteristica(nome, conteudo));
	}

	@Override
	public void setObject(XSerial obj) {

		if (obj instanceof Caracteristica) {
			try {
				agregaCaracteristica((Caracteristica) obj);
			} catch (Exception e) {
				System.out.println(e.getMessage());
			}
		}
	}
}
