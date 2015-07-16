extern int vazia, nClara, dClara, nEscura, dEscura, invalida, oponenteN, oponenteD, tabuleiro[8][8], jogador;

/*
  Fun��o que tem como objetivo retornar um inteiro, se o jogador fizer  referencia a uma casa em 
  branco a funcao retornar� 1(como verdadeiro), caso contrario, retornar� 0
*/
int semPeca(int l, int c){
    if((tabuleiro[l][c] == vazia) || (tabuleiro[l][c] == invalida))
        return (1);
    else
        return (0);
}

/*
  Fun��o que verifica a se a pe�a que est� sendo referenciada � a do oponente, retorna 1 para 
  verdadeiro e 0(zero) para falso.
*/
int verPecaOponente(int l, int c, int jgd){
    if((jgd == 1 && (tabuleiro[l][c] == dEscura || tabuleiro[l][c] == nEscura)) || (jgd == 2 && (tabuleiro[l][c] == dClara || tabuleiro[l][c] == nClara)))
        return (1);
    else
        return (0);
}

/*
  Fun��o generica que recebe 3 parametros inteiros e tem um retorno tamb�m inteiro.
  verifica��es:
  .se a casa � invalida(casa de cor branca), nunca usada;
  .se a casa est� ocupada pelo seu oponente ou dama ou pe�o;
  .Se est� ocupada pela pe�a do seu time.
*/
int jgPCsInv(int ld, int cd, int jgd){//nome da funcao: "jogar para casa invalida"
     defineOponentes(jgd);
     if(tabuleiro[ld][cd] == invalida)
        return(1);
    else if(tabuleiro[ld][cd] == oponenteN || tabuleiro[ld][cd] == oponenteD)
        return(2);
    else if((tabuleiro[ld][cd] != oponenteN || tabuleiro[ld][cd] != oponenteD) && tabuleiro[ld][cd]!= vazia)
        return(3);
    else
        return(0);
}

/*
  Fun��o que faz uma verifica��o se a casa destino em copara��o a localizacao atual avan�ou apenas
  uma casa na diagonal, recebe 5 inteiros e retorna 1 inteiro.
  se for uma pe�a normal(Pe�o).
*/
int verAvanUmaN(int l, int ld, int c, int cd, int jgd){
    if(jgd == 1){//verifica jogador 1
        if(ld == l-1 &&(cd == c+1 || cd == c-1))
            return(1);
        else
            return (0);
    }
    else{//jogador 2
        if(jgd == 2){
            if(ld == l+1 &&(cd == c+1 || cd == c-1))
                return (1);
            else
                return (0);
        }
    
    }
}

/*
  Fun��o que faz uma verifica��o se a casa destino em copara��o a localizacao atual avan�ou apenas
  uma casa na diagonal, recebe 4 inteiros e retorna 1 inteiro.
  Se for uma pe�a coroada(Dama).
*/
int verAvanUmaD(int l, int ld, int c, int cd){
    if(ld == l-1 &&(cd == c+1 || cd == c-1))
        return(1);
    else if(ld == l+1 &&(cd == c+1 || cd == c-1))
        return(1);

    return(0);
    
}

/*
  Fun��o que recebe e retorna um inteiro.
  Verifica se exista uma possibilidade de raptar a pe�a do oponente.
*/
int evitaSopro(int jgd){
    int l, c;
    defineOponentes(jgd);
    for(l=0; l<8; l++){
        for(c=0; c<8; c++){
            if(tabuleiro[l][c] == jgd || tabuleiro[l][c] == jgd*-1){//jgd ou � 1 ou 2, logo (jgd*-1) == -1 ou -2
                if((tabuleiro[l-1][c+1] == oponenteN || tabuleiro[l-1][c+1] == oponenteD)  &&  tabuleiro[l-2][c+2] == vazia){
                    if((l-2>=0 && l-2<8) && (c+2>=0 && c+2<8))//se est� dentro do tabuleiro
                        return (1);
                }
                else if((tabuleiro[l-1][c-1] == oponenteN || tabuleiro[l-1][c-1] == oponenteD) &&  tabuleiro[l-2][c-2] == vazia){
                    if((l-2>=0 && l-2<8) && (c-2>=0 && c-2<8))
                        return (1);

                }
                else if((tabuleiro[l+1][c+1] == oponenteN || tabuleiro[l+1][c+1] == oponenteD) && tabuleiro[l+2][c+2] == vazia){
                    if((l+2>=0 && l+2<8) && (c+2>=0 && c+2<8))
                        return (1);

                }
                else if((tabuleiro[l+1][c-1] == oponenteN || tabuleiro[l+1][c-1] == oponenteD) && tabuleiro[l+2][c-2]== vazia){
                    if((l+2>=0 && l+2<8) && (c-2>=0 && c-2<8))
                        return (1);
                }
            }
        }
    }
    return (0);
}
