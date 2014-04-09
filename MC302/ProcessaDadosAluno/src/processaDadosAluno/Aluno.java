package processaDadosAluno;

public class Aluno {
	
	private String nome;
	private String rg;
	private String pontuacao;
	private String curso;	
	
	public Aluno(){
		
	}
	
	public Aluno(String nome, String rg, String pontuacao, String curso){
		
		setNome(nome);
		setRg(rg);
		setPontuacao(pontuacao);
		setCurso(curso);
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String nome) {
		this.nome = nome;
	}
	
	public String getRg() {
		return rg;
	}
	
	public void setRg(String rg) {
		this.rg = rg;
	}
	
	public String getCurso() {
		return curso;
	}
	
	public void setCurso(String curso) {
		this.curso = curso;
	}
	
	public String getPontuacao() {
		return pontuacao;
	}
	
	public void setPontuacao(String pontuacao) {
		this.pontuacao = pontuacao;
	}	
}
