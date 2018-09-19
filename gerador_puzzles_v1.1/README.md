# gerador_puzzles_v1.1 
Projeto de Programação Battleship - gerador de puzzles versão 1.1

link do repositório do projeto completo(interface + gerador de puzzles) no github: https://github.com/allandemiranda/Battleship_LP 

Estratégia de Desenvolvimento:

Tópicos:
- Codificação
- Geração dos Barcos
- Verificação de Existência de Puzzles Repetidos
- Mudanças da versão 1.0 para a versão 1.1

1ª Codificação:

Foi usado uma codificação de base 16(hexadecimal) para identificar todos os tipos de barcos, e água.

Sendo:

0(zero) para água;
1 para barco de tamanho um(submarine);
2 para lado “<” do barco tamanho dois;
3 para lado “>” do barco tamanho dois;
4 para lado “^” do barco tamanho dois;
5 para lado “v” do barco tamanho dois;
6 para lado “<” do barco tamanho três;
7 para lado “>” do barco tamanho três;
8 para lado “^” do barco tamanho três;
9 para lado “v” do barco tamanho três;
A para meio “+” do barco tamanho três;
B para lado “<” do barco tamanho quatro;
C para lado “>” do barco tamanho quatro;
D para lado “^” do barco tamanho quatro;
E para lado “v” do barco tamanho quatro;
F para meio “+” do barco tamanho quatro;

2ª Geração dos Barcos:

Os barcos são colocados em ordem decrescente de tamanho, isto é, do maior para o menor. Para Cada barco é escolhido as posições i e j e a orientação do barco(vertical ou horizontal) em uma matrix buffer, e depois de efetuado todas as operações do algoritmo os puzzles são escritos em um arquivo txt nomeado conforme o template de arquivo lote-puzzles-linhasXColunas.txt(para um arquivo de 100 puzzles 7x7 o nome do arquivo seria 100-puzzles-7x7.txt) e exibidos no console(terminal).

São duas as estratégias de geração de puzzles, a primeira para os barcos de 10 linhas ou 10 colunas acima, e a outra para os barcos de 7 8 e 9 linhas ou colunas.

Primeira estratégia:

Dentro de um loop há outros 4 loops, cada um para cada tipo de barco, em cada loop são sorteados as posições i e j do barco e a orientação do barco. Exceto o primeiro barco a ser colocado(battleship) é verificado se é possível(se o barco não ultrapassa os limites do puzzle, e se as posições ao redor do barco contêm água) colocar o barco na posição e orientação sorteadas, se não for possível, o sorteio é feito novamente. 

Segunda estratégia:

para os puzzles com 7 8 9 linhas ou colunas as vezes não é possível encaixar todos os barcos no tabuleiro, por causa do tamanho do puzzle, quando isso ocorre a geração do puzzle é reiniciada do zero.

Para barcos com 7 8 linhas é colocado primeiro o battleship depois os cruisers de forma aleatória como na primeira estratégia, e então, no destroyer e submarine é verificado as posições que podem conter os barcos, dai se não for possível contêlos, a geração do puzzle inteiro é reiniciada.

Para os puzzles de 9 linhas só é necessário se preocupar com os submarines porque só eles que não conseguem encaixar as vezes, então se isso acontece reinicia-se a geração do puzzle também como com os barcos de 7 e 8 linhas ou colunas. 

3ª Verificação de existência de puzzles repetidos

Para um puzzle sair repetido é necessário que 30 sorteios aleatórios em um puzzle sejam idênticos em um outro, pois temos 3 sorteios para cada barco, os quais são: o sorteio das posições i e j e da orientação do barco. Dos sorteios das posições i e j temos muitas possibilidades, mesmo nos puzzles menores, e da orientação temos 2 possibilidas para todos os puzzles.

EX: para dois puzzles 10x10 saírem repetidos é preciso que aconteça o seguinte:

battleship:

para 100 posições do puzzle, nos dois puzzles temos que ter o battleship na mesma posição i e j, e na mesma orientação(vertical e horizontal), só a chance disso acontecer já é bem pequena.

cruiser:

temos que ter 2 cruisers nas mesmas posições i e j, e mesma orientação.

destroyer: 

é preciso que 3 destroyers tenham as mesmas posições e orientação.

submarine:

e por fim, que tenham 4 submarines nas mesmas posições, (o submarine não tem orientação).

conclusão:

Sabendo disso observamos que as chances de sair dois puzzles idênticos(de 2 até a quantidade máxima de 100 puzzles) é baixíssima(quase impossível), e então foi resolvido que não seria necessário fazer a verificação de existência de puzzles repetidos, pois, além de desnecessário, prejudicaria o desempenho do algoritmo do gerador de puzzles.

4ª Mudanças da versão 1.0 para a versão 1.1

Foi acrescentado as verificações de existência de água nas diagonais dos barcos, porque na versão 1.0 as verificações estavam sendo feitas apenas acima, abaixo, na direita e esquerda. Isso porque houve um erro de interpretação das regras, foi entendido que não precisaria verificar as diagonais, mas depois de reler as regras verificou-se o erro, e foi corrigido.

 

	



   
