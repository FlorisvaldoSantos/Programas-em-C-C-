int peso(grafo *g, int IndiceDoVertice, int i){
	return g->matrizInteira[IndiceDoVertice][i];
}

int dijkstra(grafo *g, int s, int t){
	int infinito = 99999;

	int *distancia = (int*) malloc(sizeof(int)*50);
	int *caminho = (int*) malloc(sizeof(int)*50);
	bool *perm = (bool*) malloc(sizeof(bool)*50);
	int corrente, k = s, de, j=0;
	int menordist, moradist;
	
	for(int i = 0; i < g->tamanho; i++){
		perm[i] = false;
		distancia[i] = 99999;
		caminho[i] = 99999;
	}
	perm[s] = true;
	distancia[s] = 0;
	corrente = s;

	while(corrente != t){
		menordist = infinito;
		de = distancia[corrente];

		for(int i = 0; i < g->tamanho; i++){
			if(!perm[i]){
				moradist = de + peso(g, corrente, i);
				if(moradist < distancia[i]){
					distancia[i] = moradist;
					caminho[i] = corrente;
				}
				if(distancia[i] < menordist){
					menordist = distancia[i];
					k = i;
				}
			}
		}
		corrente = k;
		perm[corrente] = true;
	}
	return distancia[t];
}
