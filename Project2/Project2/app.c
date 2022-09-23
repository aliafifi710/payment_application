#include <stdio.h>
#include "cardModule.h"
#include"terminalModule.h"
#include"serverModule.h"
extern ST_cardData_t customer1;
extern ST_terminalData_t terminal;
	void appStart(void)
	{
		ST_cardData_t ctest;
		ST_terminalData_t ter;
		ST_transaction_t ser;
		//getCardHolderName(&ctest);
		getCardExpiryDate(&ctest);
		getCardPAN(&ctest);
		isValidAccount(&ctest);
		getTransactionDate(&ter);
		isCardExpired(customer1, terminal);
		getTransactionAmount(&ter);
		setMaxAmount(&ter);
		isBelowMaxAmount(&ter);
		isAmountAvailable(&ter);
	}
	
