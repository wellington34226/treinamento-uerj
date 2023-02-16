#ifndef DEFINICOES_H
#define DEFINICOES_H
// Separação das notas musicais por NOTA (DÓ,RÉ,MI,FÁ,SOL,LÁ,SÍ), cada grupo de nota apresenta suas variações, algumas com mais ou menos varições
/*
** Classe Nota
** frequencia - frequência da nota musical a ser tocada 
** duracao    - tempo em que a nota deve ser tocada
** pausa      - tempo de pausa para a próxima nota
** proxima    - ponteiro para a próxima estrutura nota a ser tocada, ou null para finalizar
*/

#include "notas.h"
#include "tempos.h"

class Nota {
  private:
    static const unsigned int m_notasDO[];//frequências DÓ
    static const unsigned int m_notasRE[];//frequências RÉ
    static const unsigned int m_notasMI[];//frequências MI
    static const unsigned int m_notasFA[];//frequências FÁ
    static const unsigned int m_notasSOL[];//frequências SOL
    static const unsigned int m_notasLA[];//frequências LÁ
    static const unsigned int m_notasSI[];//frequências SÍ
    static const unsigned int m_tempos[];//pausas padrão

    static unsigned int m_pinoBuzzer;//pino do buzzer padrão
    static unsigned int m_compasso;//compasso
    
    unsigned int m_pino;            //pino de saída, utilizado quando a nota deve ser tocada em um pino diferente do pino padrão
    short unsigned int m_frequencia;//frequencia da nota musical
    unsigned int m_duracao;         //duração da nota em millissegundos
    unsigned int m_pausa;           //pausa para próxima nota em millissegundos
    Nota * m_proxima;               //ponteiro para a próxima nota
  public:
    /* Construtores e destrutor */
    Nota(unsigned int pino = 0,nota nota = DO,oitava oitava = QUARTA,bool sustenido = false,bool bmol = false,tempo duracao = SEMIBREVE,tempo pausa = COLCHEIA);//construtor com o pino de saída, nome da nota, oitava, sustenido?, bmol?, duracao, pausa
    Nota(Nota &proxima,unsigned int pino = 0,nota nota = DO,oitava oitava = QUARTA,bool sustenido = false,bool bmol = false,tempo duracao = SEMIBREVE,tempo pausa = COLCHEIA);//construtor com o próximo objeto Nota, nome da nota, oitava, sustenido?, bmol?, duracao e pausa
    virtual ~Nota();//destrutor
    /* Métodos de classe */
    static void init(unsigned int pino);//inicia pino padrão para o buzzer
    static void setCompasso(unsigned int compasso = 1000);//compasso em milliseguindos (padrão de um segundo)
    static void testarBuzzer(void);//testa o buzzer tocando Dó RÉ MI FÁ SOL LÁ SÍ
    /* Métodos de instância */
    void init(void);//inicia o buzzer,necessário apenas caso sejam utilizados mais de um buzzer (caso apenas um buzzer seja utilizado o pino deverá ser inicializado usando o método init estático passando o pino padrão a ser utilizado)
    void setPino(unsigned int pino = 0);//define o pino do buzzer
    void setNota(nota nota = DO,oitava oitava = QUARTA,bool sustenido = false,bool bmol = false);//define a frequência baseada na nota, oitava, sustenido? e bmol?, verificando se a nota correspondente está mapeada
    void setDuracao(tempo duracao = SEMIBREVE);//define a duração da nota (por padrão o tempo do compasso)
    void setDuracoes(tempo duracao = SEMIBREVE);//define a mesma duração para todas as notas (por padrão o tempo do compasso)
    void setPausa(tempo pausa = COLCHEIA);//define a pausa da nota (por padrão o tempo é de 1/8 do compasso)
    void setPausas(tempo pausa = COLCHEIA);//define a mesma pausa para todas as notas (por padrão o tempo é de 1/8 do compasso)
    void setProxima(Nota &proxima);//define a próxima nota
    void tocarNota(void);//toca a nota
    void tocarMusica(void);//toca todas as notas
};

#endif /* DEFINICOES_H */