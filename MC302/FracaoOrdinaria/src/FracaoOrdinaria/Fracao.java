package FracaoOrdinaria;

public class Fracao {

	private int numerador;
	private int denominador;
	
	public Fracao(int n, int d){
		
		numerador = n;
		denominador = d;
	}
	
	public Fracao add(Fracao f){
		
		Fracao soma = new Fracao(this.numerador * f.denominador + f.numerador * this.denominador,
				this.denominador * f.denominador);
		
		return this.getSimplificada(soma);
	}
	
	public Fracao sub(Fracao f){
		
		return add(new Fracao(f.numerador * -1, f.denominador));
	}
	
	public Fracao mult(Fracao f){
		
		Fracao produto = new Fracao(this.numerador * f.numerador, this.denominador * f.denominador);
		return this.getSimplificada(produto);
	}
	
	public Fracao div(Fracao f){
			
		//Cria uma nova fracao com a inversa do dividento, para efetuar a multiplicação
		Fracao auxiliar = new Fracao(f.denominador, f.numerador); 
		return mult(auxiliar);
	}
	
	public float toFloat(){
		
		return this.numerador / this.denominador;
	}
	
	public int comparesTo(Fracao f){
		
		float numeroA, numeroB;
		
		numeroA = this.numerador / this.denominador;
		numeroB = f.numerador / f.denominador;
		
		if(numeroA == numeroB)
			return 0;
		if(numeroA < numeroB)
			return -1;
					
		return 1;
	}
	
	public Fracao getSimplificada(Fracao f){
		
		return new Fracao(10,5);
	}
	
	private int retornarMdc(int a, int b){
		
		return Integer.MIN_VALUE;
	}
}
