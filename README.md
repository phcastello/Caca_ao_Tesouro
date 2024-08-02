# Jogo de Caça ao Tesouro

Este é um jogo em C++ onde jogadores exploram uma caverna em um tabuleiro para encontrar diamantes e evitar paredes e armadilhas. O objetivo é acumular pontos encontrando diamantes, e o primeiro jogador a alcançar 100 pontos vence.

## Funcionalidades

- **Inicialização e configuração do tabuleiro**: O jogo inicializa o tabuleiro escondido e o tabuleiro mostrado aos jogadores.
- **Movimento dos jogadores**: Jogadores podem se mover usando as teclas `W`, `A`, `S` e `D`.
- **Visualização**: O tabuleiro mostrado é atualizado com a posição dos jogadores e o que eles vêem ao redor.
- **Geração de diamantes**: Diamantes são posicionados aleatoriamente no tabuleiro e possuem valores diferentes de quilates.
- **Detecção de vitória**: O jogo termina quando um jogador acumula 100 ou mais pontos.

## Requisitos

- **Compilador C++**: O código foi escrito para ser compilado com um compilador C++ padrão.

## Compilação e Execução

Para compilar e executar o jogo, siga os passos abaixo:

1. **Clone o repositório**:

    ```sh
    git clone https://github.com/seu-usuario/seu-repositorio.git
    ```

2. **Navegue até o diretório do projeto**:

    ```sh
    cd seu-repositorio
    ```

3. **Compile o código**:

    ```sh
    g++ -o jogo jogo.cpp
    ```

4. **Execute o jogo**:

    ```sh
    ./jogo
    ```

## Como Jogar

1. **Seleção de Jogadores**: O jogo pede para o usuário indicar a quantidade de jogadores (entre 2 e 4) e suas iniciais.
2. **Movimentação**: Use as teclas `W` (cima), `A` (esquerda), `S` (baixo) e `D` (direita) para movimentar o jogador no tabuleiro.
3. **Objetivo**: Encontre diamantes no tabuleiro para acumular pontos. O jogo termina quando um jogador alcança 100 pontos.

## Notas

- **Pendências**: A função para colocar armadilhas e buffs ainda precisa ser implementada.
- **Bugs**: Nenhum bug foi encontrado até o momento.


---

Jogo produzido por Pedro Castello e Patrick Correa como projeto do final do primeiro periodo de faculdade na UNICENTRO Guarapuava.
