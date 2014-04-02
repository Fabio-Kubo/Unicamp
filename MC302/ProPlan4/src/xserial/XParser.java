package xserial;

/**
 * Esta classe cria uma 'fachada' para as classes 'oficiais' relacionadas
 * ao processamento de documentos XML. Aqui também é definida a classe interna
 * XHandler que implementa um tratador 'genérico' para os eventos gerados pelo
 * parser XML. O tratamento desses eventos pode disparar eventos para o objeto
 * XFactory em uso ou para os objetos que implementam a interface XSerial.
 */

import java.io.IOException;

import javax.xml.parsers.ParserConfigurationException;
import javax.xml.parsers.SAXParser;
import javax.xml.parsers.SAXParserFactory;
import org.xml.sax.Attributes;
import org.xml.sax.SAXException;
import org.xml.sax.helpers.DefaultHandler;

public class XParser {
	
	private SAXParser myParser;    // parser xml padrão da biblioteca javax.xml.parsers (opera em 'modo SAX')
	private XFactory  myFactory;   // objeto responsável pela criação dos objetos a partir do processamento do xml
	
	/**
	 * Construtor
	 * @param xf  'fábrica' de objetos responsavel pela criacao dos objetos associados a cada tag xml
	 * @throws ParserConfigurationException
	 * @throws SAXException
	 */
	public XParser(XFactory xf) throws ParserConfigurationException, SAXException{
		myParser = SAXParserFactory.newInstance().newSAXParser();
		myFactory = xf;
	}
	
	/**
	 * Método responsável pelo processamento de um documento xml contido num arquivo
	 * @param fName  nome do arquivo xml
	 * @return  'objeto raiz' representado no documento xml
	 * @throws SAXException
	 * @throws IOException
	 */
	public XSerial parse(String fName) throws SAXException, IOException{
		XHandler myHandler = new XHandler(myFactory);
		myParser.parse(fName, myHandler);
		return myHandler.upperObject;
	}
	
}

/**
 * Tratador genérico para os eventos gerados pelo sax parser 'oficial'.
 * Dependendo do 'estado' do tratamento, o tratamento de um evento dispara outros
 * eventos para a 'fábrica de objetos' ou para as classes que implementam a interface XSerial.
 *
 */
class XHandler extends DefaultHandler{
	
	private XFactory myFactory;    // 'f�brica' de objetos 
	protected XSerial upperObject; // ultimo objeto criado pela f�brica e que ainda n�o foi 'fechado' pelo parser
	private XSerial[] stack;       // pilha de objetos, usada durante o processamento
	private int top;               // �ndice do topo da pilha
	
	private void push(XSerial xs){ stack[++top] = xs; }
	
	private XSerial pop(){ return stack[top--]; }
	
	/**
	 * Construtor
	 * @param xf
	 */
	public XHandler(XFactory xf){
		myFactory = xf;
		upperObject = null;
		stack = new XSerial[20]; // deve ser suficiente...
		top = -1;
	}
	
	/**
	 *  Trata o evento de 'abertura'  de uma tag 
	 *  (disparado pelo parser ao encontrar, p. ex. <tag attr1="v" attr2="v2" >).
	 */
	@Override
	public void startElement(String uri, String localName,String tagName, 
			Attributes attribs) throws SAXException {
		XSerial oldObj = upperObject;
		if(upperObject != null) push(upperObject);
		upperObject = myFactory.makeObject(tagName,oldObj);
		if(upperObject != null){
			for(int i = 0; i < attribs.getLength(); i++) 
				upperObject.setAttrib(attribs.getQName(i), attribs.getValue(i));
		}
	}
 
	/**
	 * Trata o evento de 'fechamento' de uma tag 
	 * (disparado pelo parser ao encontrar, p. ex. </tag> )
	 * 
	 */
	@Override
	public void endElement(String uri, String localName,
		String tagName) throws SAXException {
		if(top >= 0) {
			stack[top].setObject(upperObject);
			upperObject = pop();
		}
 	}
 
	/**
	 * Trata o evento 'characters', disparado pelo 'parser' ao encontrar
	 * um texto entre a abertura e fechamento de uma tag (como p. ex. em <tag>texto</tag>).
	 */
	@Override
	public void characters(char chars[], int start, int length) throws SAXException {
		if(upperObject != null) upperObject.setText(chars, start, length);
	}
	
}