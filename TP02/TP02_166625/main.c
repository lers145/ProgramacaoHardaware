/****************************************************************************
 * Copyright (C) 2020 by Programacao de Hardware Engenharia de computacao   *
 *                                                                          *
 * This file is part of TP02.                                               *
 *                                                                          *
 * TP02 e um software livre: voce pode redistribui-lo e / ou modifica-lo    *
 * sob os termos da GNU Lesser General Public License conforme publicada    *
 * pela Free Software Foundation, seja a versao 3 da Licenca, ou            *
 * (a sua escolha) qualquer versao posterior.                               *
 *                                                                          *
 * O TP02 e distribuido na esperanca de que seja util,                      *
 * mas SEM QUALQUER GARANTIA; sem mesmo a garantia implicita de             *
 * COMERCIALIZACAO ou ADEQUACAO A UM DETERMINADO FIM. Veja o                *
 * GNU Lesser General Public License para obter mais detalhes.              *
 *                                                                          *
 * Voce deve ter recebido uma copia do GNU Lesser General Public            *
 * Licença junto com TP02. Caso contrario, consulte                         *
 *<http://www.gnu.org/licenses/>.                                           *
 * <https://www.doxygen.nl/manual/index.html>                               *
 ****************************************************************************/

/**
 * @file main.c
 * @author Marcos Pinto, Uriel Andrade, Luis Eduardo Rodrigues e Caio Figueredo
 * @date 22 Aug 2021
 * @brief <b>TP02 da materia Programacao de Hardware</b>
 *
 * O aluno(a) devera desenvolver um codigo em C, em que ele devera criar as funcoes de manipulacao de IO 
 * (usando os registros DDRx,PINx,PORTx) onde cada devera proporcionar ao usuario poder escolher qualquer 
 * pino e port que ele quiser.  Em seguida, na funcao main, o aluno devera implementar um exemplo usando 
 * as funcoes, e de preferencia para implementar como se fosse um projeto (de sua escolha. EX: Sensor de 
 * janelas).A resposta devera ser implementado cabeçalho de acordo com o exemplo deste e descricao de cada
 * comando usando Doxygen. A resposta devera ser enviada para o proprio github do aluno, e postar os 
 * arquivos fonte na tarefa do teams.
 * 
 * O envio dos arquivos deverao ser enviados os codigos fontes puros e a documentacao gerada pelo doxygen 
 * em uma pasta zipada(no teams). No seu github, deve-se colocar da forma mais organizada que o aluno achar
 * (deve-se colocar o link do github dele no codigo fonte principal).
 * 
 * @see http://inovfablab.unisanta.br
 * @see http://fabmanager.unisanta.br
 */

//https://github.com/lers145/ProgramacaoHardaware.git

#include <avr/io.h>
#include <stdio.h>
#include <string.h>

char estadoPino;

char aux0; /**< Auxiliar 0 para armazenar a string concatenada. */
char aux1; /**< Auxiliar 1 para armazenar a string concatenada. */
char aux2; /**< Auxiliar 2 para armazenar a string concatenada. */
char aux3; /**< Auxiliar 3 para armazenar a string concatenada. */

char portaUsuario; /**< Variavel para armazenar valor do usuario. */
char portaUsuario1; /**< Variavel para armazenar valor do usuario. */
char pinoUsuario; /**< Variavel para armazenar valor do usuario. */
char pinoUsuario1; /**< Variavel para armazenar valor do usuario. */

int main(void)
{
    printf("Digite a porta que o sensor esta conectado (B, C ou D): "); /**< Solicita a entrada do dados para o usuario. */
	scanf("%s",&portaUsuario); /**< Armazena a string fornecida pelo usuário. */
	aux1 = strcat('PORT', portaUsuario); /**< Concatena as strings e armazena na variavel auxiliar. */
	
	printf("Digite o valor do pino de 0 a 7: "); /**< Solicita a entrada do dados para o usuario. */
	scanf("%s",&pinoUsuario); /**< Armazena a string fornecida pelo usuário. */
	aux0 = strcat('DDR', pinoUsuario); /**< Concatena as strings e armazena na variavel auxiliar. */
	
	printf("Digite o valor do pino de 0 a 7 para o sensor: "); /**< Solicita a entrada do dados para o usuario. */
	scanf("%s",&pinoUsuario1); /**< Armazena a string fornecida pelo usuário. */
	aux2 = strcat('DDR', pinoUsuario1); /**< Concatena as strings e armazena na variavel auxiliar. */
	
	printf("Digite a porta que o sensor esta conectado (B, C ou D) para o sensor: "); /**< Solicita a entrada do dados para o usuario. */
	scanf("%s",&portaUsuario1); /**< Armazena a string fornecida pelo usuário. */
	aux3 = strcat('PIN', portaUsuario1); /**< Concatena as strings e armazena na variavel auxiliar. */
	
	return(0);
	 
	aux1 |= (1 << DDB4); /**< Configura a porta ddr1 como INPUT, utilizando a macro. (sensor) */
	estadoPino = PINC4; /**< Configura a porta ddr2 como OUTPUT, utilizando a macro.(rele - lampada) */
	
    while (1) 
    {
		int sensor = aux3 & (1 << aux3);			/**< Le o estado do sensor no pino e armazena na variavel sensor. */
		
		if(sensor == 0){ /**< Verifica se o valor da variavel e 0. */
			aux1 &= ~(1 << aux1);	/**< Aciona o LED. */
		}
		else{
			aux1 |= (1 << aux1);	/**< Desliga o Led. */
		}
    }
};

