# Jogo de Caça ao Tesouro

Este é um jogo em C++ onde jogadores exploram uma caverna em um tabuleiro para encontrar diamantes e evitar paredes e armadilhas. O objetivo é acumular pontos encontrando diamantes, e o primeiro jogador a alcançar 100 pontos vence.

Ao acessar o link abaixo, clique em run, na parte superior da tela ou aperte a tecla `f9` no seu teclado, então, desca a tela até o final.
<p>
    <a href="https://onlinegdb.com/taKpp6wls" target="_blank">Clique aqui para jogar</a>
</p>

## Funcionalidades

- **Inicialização e configuração do tabuleiro**: O jogo inicializa o tabuleiro escondido e o tabuleiro mostrado aos jogadores.
- **Movimento dos jogadores**: Jogadores podem se mover usando as teclas `W`, `A`, `S` e `D`.
- **Visualização**: O tabuleiro mostrado é atualizado com a posição dos jogadores e o que eles vêem ao redor.
- **Geração de diamantes**: Diamantes são posicionados aleatoriamente no tabuleiro e possuem valores diferentes de quilates.
- **Detecção de vitória**: O jogo termina quando um jogador acumula 100 ou mais pontos.

## Como Jogar

1. **Seleção de Jogadores**: O jogo pede para o usuário indicar a quantidade de jogadores (entre 2 e 4) e suas iniciais.
2. **Movimentação**: Use as teclas `W` (cima), `A` (esquerda), `S` (baixo) e `D` (direita) para movimentar o jogador no tabuleiro.
3. **Objetivo**: Encontre diamantes no tabuleiro para acumular pontos. O jogo termina quando um jogador alcança 50 pontos.

## Compilação e Execução (caso queira)

Para compilar e executar o jogo, siga os passos abaixo:

1. **Clone o repositório**:

    ```sh
    git clone https://github.com/phcastello/esse-repositorio.git
    ```

2. **Navegue até o diretório do projeto**:

    ```sh
    cd esse-repositorio
    ```

3. **Compile o código**:

    ```sh
    g++ -o jogo main.cpp
    ```

4. **Execute o jogo**:

    ```sh
    ./jogo
    ```

## Notas

- **Pendências**: Nenhuma, jogo completo.
- **Bugs**: Nenhum bug foi encontrado até o momento.
- **Melhorias**: O codigo pode se tornar mais eficiente e claro com polimento e refatoração de codigo, contudo, o propósito desse repositório é armazenar a minha trajetória durante a faculdade de Ciência da Computação.

---

Jogo produzido por Pedro Castello e Patrick Correa como projeto do final do primeiro periodo de faculdade na UNICENTRO Guarapuava.
