#ifndef RECEPTOR_H
#define RECEPTOR_H
#include "definicoes.h"

#ifdef RECEPTOR

#include <Arduino.h>
#include <RH_ASK.h>//https://github.com/PaulStoffregen/RadioHead
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>//baixar do gerenciador de bibliotecas e confirmar a instalação das demais dependências
//https://www.electrocreativity.com/post/plotting-rolling-graph-on-oled

// Definir o tamanho da tela em pixels
#define LARGURA 128
#define ALTURA 32
// Definir quantidade de gráficos a serem plotados
#define GRAFICOS 3

#define REINICIA_TELA -1 // pino para reinicialização # (-1 para compartilhar o pino de reset do Arduino)

class Receptor {
  private:
    // Atributos de classe
    static RH_ASK m_receptor;//objeto para comunicação sem fio
    static uint8_t m_estados;// array de bool para indicação dos estados da execução 0 | 0 | 0 | 0 | 0 | 0 | 0 | 0
    static uint8_t m_dados[];// Buffer para armazenar a mensagem recebida
    static uint8_t m_tamanho;// tamanho dos dados recebidos
    static Adafruit_SSD1306 m_tela;// objeto para utilização da tela
    static String m_texto;// texto para impressão no topo da tela
    static uint8_t m_graficos[][LARGURA];// matriz de gráficos, cada linha mantém as informações de um gráfico para cada pino analógico recebido
    // Métodos privados estáticos
    static void receberDados(void);
    static void atualizarTela(void);
    static void imprimirMensagem(void);
  public:
    Receptor();//Construtyor padrão
    virtual ~Receptor();//destrutor
    // Métodos estáticos públicos
    static void init(void);
    static void loop(void);
};
#endif /* RECEPTOR_H */
#endif