#include"serverModule.h"
#include "terminalModule.h"
#include"standards.h"
#include <string.h>
extern ST_cardData_t customer1;
extern ST_terminalData_t terminal;
ST_cardData_t cardInformation;
ST_terminalData_t terminalInformation;
uint8_t pos =-55;
uint8_t checkAcc;

void start_DB(void) {
    ST_accountsDB_t acc1 = { 8000,"0135792468aliafifi" };
    ST_accountsDB_t acc2 = { 2000,"123456789123456789" };
    ST_accountsDB_t acc3 = { 3000,"010203040506070809" };
    ST_accountsDB_t acc4 = { 4000,"010203040506070809" };
    ST_accountsDB_t acc5 = { 5000,"010203040506070809" };
    ST_accountsDB_t acc6 = { 6000,"010203040506070809" };
    ST_accountsDB_t acc7 = { 7000,"010203040506070809" };
    ST_accountsDB_t acc8 = { 8000,"010203040506070809" };
    ST_accountsDB_t acc9 = { 9000,"010203040506070809" };
    ST_accountsDB_t acc10 ={ 10000,"010203040506070809" };
    accArr[0] = acc1;
    accArr[1] = acc2;
    accArr[2] = acc3;
    accArr[3] = acc4;
    accArr[4] = acc5;
    accArr[5] = acc6;
    accArr[6] = acc7;
    accArr[7] = acc8;
    accArr[8] = acc9;
    accArr[9] = acc10;

}
EN_serverError_t isValidAccount(ST_cardData_t* cardData) {
    start_DB();
    cardData = &customer1;
    uint8_t check = 0;
    for (int i = 0; i < 3; i++) {
        if (!(strcmp((cardData->primaryAccountNumber), accArr[i].primaryAccountNumber))) {
            printf("Account is available\n");
            pos = i;
            check = 1;
            checkAcc = ok;
            return ok;
        }
        else {
            check = 0;
        }
        if (i == 2 && check == 0) {
            printf("Account not found!\n");
            return ACCOUNT_NOT_FOUND;
        }

    }
}

EN_serverError_t isAmountAvailable(ST_terminalData_t* termData) {
    termData = &terminal;
    if (pos != -55) {
        if ((termData->transAmount) > accArr[pos].balance) {
            printf("Your tansaction amount is more than your balance\n");
            return LOW_BALANCE;
        }
        else {
            printf("Your transaction will proceed\n");
            checkAcc = ok;
            return ok;
        }
    }

}
EN_transState_t recieveTransactionData(ST_transaction_t* transData) {
    if ((isValidAccount(&customer1)) == ACCOUNT_NOT_FOUND) {
        printf("DECLINED STOLEN");
        return DECLINED_STOLEN_CARD;
    }
    if ((isAmountAvailable(&terminal)) == LOW_BALANCE) {
        printf("DECLINED low balance");
        return DECLINED_INSUFFECIENT_FUND;
    }
    /*if ((saveFlag == SAVING_FAILED)) {
        printf("internal server error");
        return INTERNAL_SERVER_ERROR;
    }*/
    else {
        ((accArr[pos]).balance) = ((accArr[pos]).balance) - terminal.transAmount;
        printf("after approval %0.2f\n", (accArr[pos].balance));
        return APPROVED;
    }

}
