package prodPlan;

import xserial.XSerial;

public abstract class Parte implements XSerial {

	protected int cod;
	protected String nome;
	protected String descricao;
	protected float valor;

	public Parte() {

	}

	public Parte(int cod, String nome, String descricao, float valor) {

		this.cod = cod;
		this.nome = nome;
		this.descricao = descricao;
		this.valor = valor;
	}

	public float calculaValor() {

		return this.valor;
	}

	public String toString() {

		StringBuilder stb = new StringBuilder();
		stb.append("codigo:");
		stb.append(this.cod);
		stb.append(" nome:");
		stb.append(this.nome);
		stb.append(" descrição:");
		stb.append(this.descricao);
		stb.append(" valor:");
		stb.append(this.valor);

		return stb.toString();
	}

	@Override
	public void setAttrib(String name, String value) {

		if (name.equals("cod")) {
			this.cod = Integer.parseInt(value);
		} else if (name.equals("nome")) {
			this.nome = value;
		} else if (name.equals("descricao")) {
			this.descricao = value;
		} else if (name.equals("valor")) {
			this.valor = Float.parseFloat(value);
		}

	}

	@Override
	public void setText(char[] chars, int start, int length) {
		// TODO Auto-generated method stub

	}

}
