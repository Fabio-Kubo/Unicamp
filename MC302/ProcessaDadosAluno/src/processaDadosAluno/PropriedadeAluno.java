package processaDadosAluno;

public enum PropriedadeAluno {

	NOME(0), RG(1), CURSO(3);

	private int code;

	private PropriedadeAluno(int c) {
		code = c;
	}

	public int getCode() {
		return code;
	}
}
