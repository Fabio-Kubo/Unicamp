package prodPlan;

import java.io.IOException;
import java.util.List;

import javax.xml.parsers.ParserConfigurationException;

import org.xml.sax.SAXException;

import xserial.XParser;

public class TesteLab4_1 {

	static void imprimeLista(List<Item> lista, int nivel){
		String s1 = "\t", s2 = "\t";
		for(int i = 0; i < nivel; i++) s1 += "..";
		for(int i = 3; i > nivel; i--) s2 += "  ";
		s2 += "\t";
		for(Item item:lista){
			System.out.println(s1 + item.parte.cod+"\t\t"+item.quantidade+"\t"+item.calculaValor()+ s2+s1+item.parte.nome+"/"+item.parte.descricao);
			if(item.parte instanceof ParteComposta) imprimeLista(((ParteComposta)item.parte).listaDeItens(),nivel+1);
		}
	}
	
	static void imprimeTotal(List<Item> lista){
		float total = 0.0f;
		for(Item item:lista) total += item.calculaValor();
		System.out.println("Valor Total:"+total);
	}
	
	/**
	 * @param args
	 * @throws SAXException 
	 * @throws ParserConfigurationException 
	 * @throws IOException 
	 */
	public static void main(String[] args) throws ParserConfigurationException, SAXException, IOException {
		// criação do objeto XParser
		XParser xp = new XParser(new MyFactory());
		
		// processamento do documento xml 
		Lista lista = (Lista) xp.parse("lista1.xml");
		
		// Escreve a lista (mais ou menos) formatada na sa�da padr�o
		System.out.println("\t CODIGO\t    QUANTIDADE \tVALOR  \t\t NOME/DESCRICAO");
		imprimeLista(lista.listaDeItens(),0);
	    imprimeTotal(lista.listaDeItens());
	    System.out.println("FIM");

	}

}
