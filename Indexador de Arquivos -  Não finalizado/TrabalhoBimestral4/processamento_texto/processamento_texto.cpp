
#include"processamento_texto.h"
#include"..\Hash\hash.h"

processamento_texto::processamento_texto(){
		
		
		this->asciivector[0] = ' ';
		this->asciivector[1] = ' ';
		this->asciivector[2] = ' ';
		this->asciivector[3] = ' ';
		this->asciivector[4] = ' ';
		this->asciivector[5] = ' ';
		this->asciivector[6] = ' ';
		this->asciivector[7] = ' ';
		this->asciivector[8] = ' ';
		this->asciivector[9] = ' ';
		this->asciivector[10] = ' ';
		this->asciivector[11] = ' ';
		this->asciivector[12] = ' ';
		this->asciivector[13] = ' ';
		this->asciivector[14] = ' ';
		this->asciivector[15] = ' ';
		this->asciivector[16] = ' ';
		this->asciivector[17] = ' ';
		this->asciivector[18] = ' ';
		this->asciivector[19] = ' ';
		this->asciivector[20] = ' ';
		this->asciivector[21] = ' ';
		this->asciivector[22] = ' ';
		this->asciivector[23] = ' ';
		this->asciivector[24] = ' ';
		this->asciivector[25] = ' ';
		this->asciivector[26] = ' ';
		this->asciivector[27] = ' ';
		this->asciivector[28] = ' ';
		this->asciivector[29] = ' ';
		this->asciivector[30] = ' ';
		this->asciivector[31] = ' ';
		this->asciivector[32] = ' ';
		this->asciivector[33] = ' ';
		this->asciivector[34] = ' ';
		this->asciivector[35] = ' ';
		this->asciivector[36] = ' ';
		this->asciivector[37] = ' ';
		this->asciivector[38] = ' ';
		this->asciivector[39] = ' ';
		this->asciivector[40] = ' ';
		this->asciivector[41] = ' ';
		this->asciivector[42] = ' ';
		this->asciivector[43] = ' ';
		this->asciivector[44] = ' ';
		this->asciivector[45] = ' ';
		this->asciivector[46] = ' ';
		this->asciivector[47] = ' ';
		this->asciivector[48] = '0';
		this->asciivector[49] = '1';
		this->asciivector[50] = '2';
		this->asciivector[51] = '3';
		this->asciivector[52] = '4';
		this->asciivector[53] = '5';
		this->asciivector[54] = '6';
		this->asciivector[55] = '7';
		this->asciivector[56] = '8';
		this->asciivector[57] = '9';
		this->asciivector[58] = ' ';
		this->asciivector[59] = ' ';
		this->asciivector[60] = ' ';
		this->asciivector[61] = ' ';
		this->asciivector[62] = ' ';
		this->asciivector[63] = ' ';
		this->asciivector[64] = '@';
		this->asciivector[65] = 'a';
		this->asciivector[66] = 'b';
		this->asciivector[67] = 'c';
		this->asciivector[68] = 'd';
		this->asciivector[69] = 'e';
		this->asciivector[70] = 'f';
		this->asciivector[71] = 'g';
		this->asciivector[72] = 'h';
		this->asciivector[73] = 'i';
		this->asciivector[74] = 'j';
		this->asciivector[75] = 'k';
		this->asciivector[76] = 'l';
		this->asciivector[77] = 'm';
		this->asciivector[78] = 'n';
		this->asciivector[79] = 'o';
		this->asciivector[80] = 'p';
		this->asciivector[81] = 'q';
		this->asciivector[82] = 'r';
		this->asciivector[83] = 's';
		this->asciivector[84] = 't';
		this->asciivector[85] = 'u';
		this->asciivector[86] = 'v';
		this->asciivector[87] = 'w';
		this->asciivector[88] = 'x';
		this->asciivector[89] = 'y';
		this->asciivector[90] = 'z';
		this->asciivector[91] = ' ';
		this->asciivector[92] = ' ';
		this->asciivector[93] = ' ';
		this->asciivector[94] = ' ';
		this->asciivector[95] = ' ';
		this->asciivector[96] = ' ';
		this->asciivector[97] = 'a';
		this->asciivector[98] = 'b';
		this->asciivector[99] = 'c';
		this->asciivector[100] = 'd';
		this->asciivector[101] = 'e';
		this->asciivector[102] = 'f';
		this->asciivector[103] = 'g';
		this->asciivector[104] = 'h';
		this->asciivector[105] = 'i';
		this->asciivector[106] = 'j';
		this->asciivector[107] = 'k';
		this->asciivector[108] = 'l';
		this->asciivector[109] = 'm';
		this->asciivector[110] = 'n';
		this->asciivector[111] = 'o';
		this->asciivector[112] = 'p';
		this->asciivector[113] = 'q';
		this->asciivector[114] = 'r';
		this->asciivector[115] = 's';
		this->asciivector[116] = 't';
		this->asciivector[117] = 'u';
		this->asciivector[118] = 'v';
		this->asciivector[119] = 'w';
		this->asciivector[120] = 'x';
		this->asciivector[121] = 'y';
		this->asciivector[122] = 'z';
		this->asciivector[123] = ' ';
		this->asciivector[124] = ' ';
		this->asciivector[125] = ' ';
		this->asciivector[126] = ' ';
		this->asciivector[127] = ' ';
		this->asciivector[128] = 'c';
		this->asciivector[129] = 'u';
		this->asciivector[130] = 'e';
		this->asciivector[131] = 'a';
		this->asciivector[132] = 'a';
		this->asciivector[133] = 'a';
		this->asciivector[134] = 'a';
		this->asciivector[135] = 'c';
		this->asciivector[136] = 'e';
		this->asciivector[137] = 'e';
		this->asciivector[138] = 'e';
		this->asciivector[139] = 'i';
		this->asciivector[140] = 'i';
		this->asciivector[141] = 'i';
		this->asciivector[142] = 'a';
		this->asciivector[143] = 'a';
		this->asciivector[144] = 'e';
		this->asciivector[145] = ' ';
		this->asciivector[146] = ' ';
		this->asciivector[147] = 'o';
		this->asciivector[148] = 'o';
		this->asciivector[149] = 'o';
		this->asciivector[150] = 'u';
		this->asciivector[151] = 'u';
		this->asciivector[152] = ' ';
		this->asciivector[153] = 'o';
		this->asciivector[154] = 'u';
		this->asciivector[155] = ' ';
		this->asciivector[156] = ' ';
		this->asciivector[157] = ' ';
		this->asciivector[158] = 'x';
		this->asciivector[159] = ' ';
		this->asciivector[160] = 'a';
		this->asciivector[161] = 'i';
		this->asciivector[162] = 'o';
		this->asciivector[163] = 'u';
		this->asciivector[164] = 'n';
		this->asciivector[165] = 'n';
		this->asciivector[166] = ' ';
		this->asciivector[167] = ' ';
		this->asciivector[168] = ' ';
		this->asciivector[169] = ' ';
		this->asciivector[170] = ' ';
		this->asciivector[171] = ' ';
		this->asciivector[172] = ' ';
		this->asciivector[173] = ' ';
		this->asciivector[174] = ' ';
		this->asciivector[175] = ' ';
		this->asciivector[176] = ' ';
		this->asciivector[177] = ' ';
		this->asciivector[178] = ' ';
		this->asciivector[179] = ' ';
		this->asciivector[180] = ' ';
		this->asciivector[181] = 'a';
		this->asciivector[182] = 'a';
		this->asciivector[183] = 'a';
		this->asciivector[184] = ' ';
		this->asciivector[185] = ' ';
		this->asciivector[186] = ' ';
		this->asciivector[187] = ' ';
		this->asciivector[188] = ' ';
		this->asciivector[189] = ' ';
		this->asciivector[190] = ' ';
		this->asciivector[191] = ' ';
		this->asciivector[192] = 'a';
		this->asciivector[193] = 'a';
		this->asciivector[194] = 'a';
		this->asciivector[195] = 'a';
		this->asciivector[196] = 'a';
		this->asciivector[197] = 'a';
		this->asciivector[198] = ' ';
		this->asciivector[199] = 'c';
		this->asciivector[200] = 'e';
		this->asciivector[201] = 'e';
		this->asciivector[202] = 'e';
		this->asciivector[203] = 'e';
		this->asciivector[204] = 'i';
		this->asciivector[205] = 'i';
		this->asciivector[206] = 'i';
		this->asciivector[207] = 'i';
		this->asciivector[208] = ' ';
		this->asciivector[209] = 'n';
		this->asciivector[210] = 'o';
		this->asciivector[211] = 'o';
		this->asciivector[212] = 'o';
		this->asciivector[213] = 'o';
		this->asciivector[214] = 'o';
		this->asciivector[215] = ' ';
		this->asciivector[216] = ' ';
		this->asciivector[217] = ' ';
		this->asciivector[218] = ' ';
		this->asciivector[219] = ' ';
		this->asciivector[220] = ' ';
		this->asciivector[221] = ' ';
		this->asciivector[222] = ' ';
		this->asciivector[223] = ' ';
		this->asciivector[224] = 'a';
		this->asciivector[225] = 'a';
		this->asciivector[226] = 'a';
		this->asciivector[227] = 'a';
		this->asciivector[228] = 'a';
		this->asciivector[229] = 'a';
		this->asciivector[230] = ' ';
		this->asciivector[231] = 'c';
		this->asciivector[232] = 'e';
		this->asciivector[233] = 'e';
		this->asciivector[234] = 'e';
		this->asciivector[235] = 'e';
		this->asciivector[236] = 'i';
		this->asciivector[237] = 'i';
		this->asciivector[238] = 'i';
		this->asciivector[239] = 'i';
		this->asciivector[240] = ' ';
		this->asciivector[241] = 'n';
		this->asciivector[242] = 'o';
		this->asciivector[243] = 'o';
		this->asciivector[244] = 'o';
		this->asciivector[245] = 'o';
		this->asciivector[246] = 'o';
		this->asciivector[247] = ' ';
		this->asciivector[248] = ' ';
		this->asciivector[249] = 'u';
		this->asciivector[250] = 'u';
		this->asciivector[251] = 'u';
		this->asciivector[252] = 'u';
		this->asciivector[253] = ' ';
		this->asciivector[254] = ' ';
		// carrega o vetor com as stopwords
		loadstopwords();
}

char processamento_texto::equivalente(unsigned char value){
	
	unsigned int i =(int)value;
	return this->asciivector[i];
}
void processamento_texto::mostrachar(){
	
	for(int i=0;i<255;i++){
		cout<<this->asciivector[i]<<" - "<< (int)i<<endl;	
	}
}

bool processamento_texto::limpastring(ifstream &arq_entrada){
	
	//cout << static_cast<unsigned char>(225) << endl;
	unsigned char entrada, char_equi;
	ofstream buffer;
	buffer.open("Buffer_texto.txt");
	
	while(arq_entrada.good()){
	
		entrada = arq_entrada.get();
		
		if(arq_entrada.good()){
			char_equi = equivalente(entrada);
			buffer<<char_equi;
		}
	}
	buffer.close();
	return true;
}

string processamento_texto::reconhecetoken(ifstream &arq_entrada){
	
	string palavra;
	char c;
	while(arq_entrada.good() && palavra.length() == 0 ) {
		do{
			c = arq_entrada.get();
			if(c != -1){
				c = equivalente(c);
				if(!isspace(c) && c!='\n'){
					palavra += c;
				}
			}
			else{
				// condição de final de arquivo.
				return palavra = "0";
			}
		}while(!isspace(c)  && c!='\n' && arq_entrada.good());
	}

	if(palavra.length() != NULL)
		return palavra;

}

void processamento_texto::loadstopwords(){

	int  i=0;
	string valor ; 
	ifstream stopwords;
	stopwords.open("stopwords.txt");
	
	while(stopwords.good() && i < 235){
		
		getline(stopwords, valor);
		if(stopwords.good()){
			vetorstop[i] = valor;
			//cout<<"valor ascii["<<i<<"]: "<<vetorstop[i]<<endl;
			i++;
		}
	}
	stopwords.close();
}
bool processamento_texto::buscabinaria(string valor){
	
	int meio = 0, inicio =0, fim =235;

	do{
		meio = ((inicio + fim)/2);
		if(this->vetorstop[meio] == valor)
			return true;
		else if(this->vetorstop[meio].compare(valor) == 1)
			fim = (meio - 1);
		else
			inicio = (meio + 1);
	
	}while(inicio < fim);

	return false;
}


HASH *processamento_texto::removestopwords(ifstream &leitura, string nome){
	
	LISTA *lista = new LISTA();
	HASH *hash;
	NO *no;
	
	char buffer[1000] = "";
	string palavra;
	leitura.clear();
	int i=0;
	bool good = true;
	while(good){
		
		palavra = reconhecetoken(leitura);
		if(palavra.compare("0")==0)
			good = false;
		else{
			if(!buscabinaria(palavra)){
				lista->Insere(palavra);
			}
		}
		palavra.clear();
	}
	// aloca a hash de retorno  com 
	//seto o nome do arquivo 
	i = lista->tamlista();
	hash = new HASH(i);
		
	no = lista->getlista();
	while(no!=NULL){
		palavra = no->getstring();
		strcpy(buffer,palavra.c_str());
		hash->inserepalavras(buffer, no->getincremento(), nome);
		no = no->getnext();
	}

	return hash;

}

