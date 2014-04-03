package prodPlan;

import xserial.XSerial;

public class Caracteristica implements XSerial {

	protected String nome;
	protected String conteudo;

	public Caracteristica() {

	}

	public Caracteristica(String nome, String conteudo) {

		this.nome = nome;
		this.conteudo = conteudo;
	}

	@Override
	public void setObject(XSerial obj) {
		// TODO Auto-generated method stub
	}

	@Override
	public void setAttrib(String name, String value) {

		if (name.equals("nome")) {
			this.nome = value;
		} else if (nome.equals("conteudo")) {
			this.conteudo = value;
		}
	}

	@Override
	public void setText(char[] chars, int start, int length) {
		// TODO Auto-generated method stub

	}

}
