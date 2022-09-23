#include "cardModule.h"
#include <stdio.h>

ST_cardData_t customer1;

uint8_t flagDate = WRONG_EXP_DATE;
uint8_t element;



EN_cardError_t getCardHolderName(ST_cardData_t* cardData)
{
	uint8_t flagName = WRONG_NAME;

	cardData = &customer1;
	while (flagName == WRONG_NAME)
	{
		element = 0;
		printf("please enter your name between 20 to 24 characters\n");
		gets(cardData->cardHolderName);
		while ((cardData->cardHolderName)[element] != '\0')
		{
			element++;
		}

		if (element >= 20 && element <= 24 && element != 0) {
			flagName = OK;

			printf("valid name\n");
			return OK;
		}
		else {
			printf("Invaled Name\n");

			//return WRONG_NAME; //the progrm will terminate if we typed return WRONG_NAME; 
			//so we will continue to ask the user to insert a name untill it's valid
		}
	}

}
EN_cardError_t getCardExpiryDate(ST_cardData_t* cardData)
{
	cardData = &customer1;



	while (flagDate == WRONG_EXP_DATE)
	{
		printf("please enter expiry date in the form of mm/yy \n");
		gets(cardData->cardExpirationDate);

		while ((cardData->cardExpirationDate)[element] != '\0')
		{
			element++;
		}

		if (element < 5 || element > 5 || element == 0 || (cardData->cardExpirationDate)[2] != '/') {
			printf("Invalid date format\n");
			//return WRONG_EXP_DATE;     //the progrm will terminate if we typed return WRONG_EXP_DAT; 
										//so we will continue to ask the user to insert a DATE untilL it's valid

		}
		else {
			uint8_t good;
			for (int i = 0; i < 5; i++)
			{
				if (i != 2)
				{
					if (((cardData->cardExpirationDate)[i] >= '0') && ((cardData->cardExpirationDate)[i] <= '9'))
					{
						flagDate = OK;
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
				printf("valid expiry date\n");
			}
			else
			{
				printf("Invaled expiry date \n");
			}
		}
	}
	return OK;
}
EN_cardError_t getCardPAN(ST_cardData_t* cardData)
{
	uint8_t flagNumber = WRONG_NAME;

	cardData = &customer1;
	while (flagNumber == WRONG_NAME)
	{
		element = 0;
		printf("please enter the card's Primary Account Number PAN\n");
		gets(cardData->primaryAccountNumber);
		while ((cardData->primaryAccountNumber)[element] != '\0')
		{
			element++;
		}

		if (element >= 16 && element <= 19 && element != 0) {
			flagNumber = OK;

			printf("valid PAN\n");
			return OK;
		}
		else {
			printf("Invaled PAN\n");

			//return WRONG_PAN; //the progrm will terminate if we typed return WRONG_PAN; 
			//so we will continue to ask the user to insert a PAN untill it's valid
		}
	}

}