#include "terminalModule.h"
#include<stdio.h>

ST_terminalData_t terminal;

EN_terminalError_t getTransactionDate(ST_terminalData_t* termData)
{
	termData = &terminal;
	uint8_t element=0;
	uint8_t flagtrans = WRONG_DATE;
	while (flagtrans == WRONG_DATE)
	{
		printf("please enter transaction date in the form of dd/mm/yyyy \n");
		gets(termData->transactionDate);

		while ((termData->transactionDate)[element] != '\0')
		{
			element++;
		}

		if (element < 10 || element > 10 || element == 0 || (termData->transactionDate)[2] != '/' || (termData->transactionDate)[2] != '/') {
			printf("Invalid date format\n");
			//return WRONG_DATE;     //the progrm will terminate if we typed return WRONG_DATE; 
										//so we will continue to ask the user to insert a DATE untilL it's valid

		}
		else {
			uint8_t good;
			for (int i = 0; i < 10; i++)
			{
				if (i != 2 || i != 5)
				{
					if (((termData->transactionDate)[i] >= '0') && ((termData->transactionDate)[i] <= '9'))
					{
						flagtrans = OK;
						good = 1;
					}
					else
					{
						good = 0;
					}
				}
			}
			if (good == 1)
			{
				printf("valid transaction date\n");
				return OK;
			}
			else
			{
				printf("Invaled transaction date \n");
			}
		}
	}
	return OK;
}


/********************************************************************************/

EN_terminalError_t getTransactionAmount(ST_terminalData_t* termData)
{

	uint8_t amountFlag = INVALID_AMOUNT;
	termData = &terminal;
	termData->maxTransAmount = 5000;

	while (amountFlag == INVALID_AMOUNT)
	{
		printf("please enter the transaction amount \n");
		scanf_s("%f", &(termData->transAmount));
		if(termData->transAmount <=0 )
		{
			printf("Invalid amount please enter a correct one \n");
			//return INVALID_AMOUNT;       //the progrm will terminate if we typed return INVALID_AMOUNT; 
										//so we will continue to ask the user to insert an AMOUNT untilL it's valid
		}
		else
		{
			printf("Valid amount \n");
			return OK;
		}



	}
}

/***************************************************************************************/

EN_terminalError_t setMaxAmount(ST_terminalData_t* termData)

{ 

	              ///////////////IF NOT TAKING THE VALUE FROM USER/////////////////////////
	termData = &terminal;

    #define MAX_TRANS_AMOUNT 10000;
	termData->maxTransAmount = MAX_TRANS_AMOUNT;
	if(termData->maxTransAmount <=0)
	{
		printf("Invalid MAX_TRANS_AMOUNT  \n");

		return INVALID_AMOUNT;      
	}
	else
	{
		printf("Valid MAX_TRANS_AMOUNT \n");
		return OK;
	}
	                    /////////////////    IF TAKING THE AMOUNT FROM USER///////////////////////////

	//uint8_t flagMax = INVALID_MAX_AMOUNT;
	//while (flagMax == INVALID_MAX_AMOUNT)
	//{
	//	printf("please enter the Max transaction amount \n");
	//	scanf_s("%f", &(termData->maxTransAmount));
	//	if (termData->maxTransAmount <= 0)
	//	{
	//		printf("Invalid Max amount please enter a correct one \n");
	//		return INVALID_MAX_AMOUNT;       //the progrm will terminate if we typed return INVALID_AMOUNT; 
	//									so we will continue to ask the user to insert an AMOUNT untilL it's valid
	//	}
	//	else
	//	{
	//		printf("Valid Max amount \n");
	//		return OK;
	//	}
	//}
}
                         /**************************************************************/

EN_terminalError_t isBelowMaxAmount(ST_terminalData_t* termData)
{
	termData = &terminal;
	if ((termData->transAmount) > (termData->maxTransAmount) )
	{
		printf("Exceeded maximum amount \n");
		return EXCEED_MAX_AMOUNT;       //the progrm will terminate if we typed return EXCEED_MAX_AMOUNT; 
	}
	else
	{
		printf("Succesfull transaction \n");
		return OK;
	}
}

EN_terminalError_t isCardExpired(ST_cardData_t cardData, ST_terminalData_t termData)
{
	int cardExpMonth = ((cardData.cardExpirationDate[0] - '0') * 10) + cardData.cardExpirationDate[1] - '0';
	int cardExpYear = (((cardData.cardExpirationDate[3] ) * 10) + (cardData.cardExpirationDate[4] )) ;
	int transMonth = ((termData.transactionDate[3] - '0') * 10) + termData.transactionDate[4] - '0';
	int transYear = ((termData.transactionDate[8]) * 10) + (termData.transactionDate[9]);
	
	if (transYear > cardExpYear) {
		printf("EXPIRED CARD\n");
		return EXPIRED_CARD;

	}
	if (transYear == cardExpYear && transMonth > cardExpMonth) {
		printf("EXPIRED CARD\n");
		return EXPIRED_CARD;

	}
		printf("VALID CARD\n");
		return OK;
}



