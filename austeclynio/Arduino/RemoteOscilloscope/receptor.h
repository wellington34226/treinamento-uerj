#ifndef RECEPTOR_H
#define RECEPTOR_H
#include "definicoes.h"

#ifdef RECEPTOR

#include <RH_ASK.h>//https://github.com/PaulStoffregen/RadioHead
#include <Adafruit_SSD1306.h>//baixar do gerenciador de bibliotecas e confirmar a instalação das demais dependências
#include <Adafruit_GFX.h>

#define SSD1306_NO_SPLASH // desativa SPLASH
#define SSD1306_128_32
#define SCREEN_WIDTH 128// Definir largura da tela em pixels
#define SCREEN_HEIGHT 32// Definir altura da tela em pixels
#define SCREEN_ADDRESS 0x3C// endereço I2C do display
#define OLED_RESET -1  // pino para reinicialização # (-1 para compartilhar o pino de reset do Arduino)
#define GRAFICOS 3  // Definir quantidade de gráficos a serem plotados (máximo de 16 saídas)
#define VLARGURA 30 // espaçamento horizontal do eixo vertical 
#define VALTURA 8   // largura do TIC do eixo vertical
#define TLARGURA 5  // espaçamento vertical do eixo vertical
#define GAPGRAFICO 2   // espaçamento horizontal entre o eixo vertical e o gráfico
#define GLARGURA (SCREEN_WIDTH-VLARGURA-GAPGRAFICO) // largura da área do gráfico (cada ponto do gráfico utiliza 3 pixels, foi necessário devido ao uso de memória)
#define INTERVALO 10//intervalo em segundos para trocar o gráfico apresentado no display

class Receptor {
  private:
    // Atributos de classe
    static RH_ASK m_receptor;//objeto para comunicação sem fio
    static Adafruit_SSD1306 m_tela;// objeto para utilização da tela linhas agrupadas em páginas cada página com 128x8pixels, quantidade de páginas de acordo com a altura da tela ALTURA/8
    static uint8_t m_estados;// array de bool para indicação dos estados da execução SAÍDA  ANALÓGICA (4 bits - máximo 16 saídas) | TIPO DE GRÁFICO (digital 0 ou volts 1) | ATUALIZAR DISPLAY | DISPLAY INICIADO | RECEPTOR
    static uint8_t m_dados[];// Buffer para armazenar a mensagem recebida
    static uint8_t m_tamanho;// tamanho dos dados recebidos
    static uint16_t m_entradas[];// últimos valores recebidos
    /** Matriz de gráficos
      Mantém os gráficos de cada entrada
      Material de apoio
      https://github.com/makeabilitylab/arduino/tree/master/OLED
      http://www.technoblogy.com/show?23OS
      
    */
    static uint8_t m_graficos[][GLARGURA];
    // Métodos privados estáticos
    static void receberDados(void);
    static void atualizarDados(void);
    static void atualizarTela(void);
    static void imprimirMensagem(void);
  public:
    Receptor();//Construtyor padrão
    virtual ~Receptor();//destrutor
    // Métodos estáticos públicos
    static void init(void);
    static void loop(void);
    static void ativarAtualizacao(void);
    static void desativarAtualizacao(void);
    static void trocarGrafico(void);
};
void configurarTimer(void);
#endif /* RECEPTOR */
#endif /* RECEPTOR_H */
