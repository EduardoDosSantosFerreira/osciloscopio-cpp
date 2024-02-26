# Osciloscópio Simples com Display LCD em Arduino

![Osciloscópio](https://github.com/EduardoDosSantosFerreira/Oscilosc-pio-/blob/main/Osciloscópio.png)

O código fornecido implementa um osciloscópio simples utilizando um Arduino e um display LCD. Este osciloscópio é capaz de visualizar a variação de um sinal analógico ao longo do tempo, representando-o por meio de barras de nível e números no display LCD.

## Componentes Utilizados

- Arduino board
- Display LCD 16x2
- Sensor de entrada analógica

## Funcionalidades do Código

1. **Configuração Inicial do Display LCD**

   - O display LCD é inicializado no método `setup`.
   - Caracteres personalizados são criados para representar as barras de nível.

2. **Leitura e Processamento do Sensor de Entrada Analógica**

   - O sensor de entrada analógica é lido no loop principal (`loop`).
   - Os valores lidos são processados para determinar o nível de repetição e a exibição correspondente no display LCD.

3. **Exibição da Representação do Sinal no Display LCD**

   - Com base nos valores lidos, o código determina as barras de nível mais representativas e os números de repetição correspondentes.
   - Essas informações são exibidas no display LCD, proporcionando uma representação visual da variação do sinal analógico ao longo do tempo.

## Considerações Finais

Este osciloscópio simples demonstra como utilizar um Arduino e um display LCD para visualizar a variação de um sinal analógico. A representação gráfica das leituras analógicas permite uma compreensão visual imediata da variação do sinal, sendo útil em projetos que exigem monitoramento e visualização de sinais analógicos de forma simplificada.
