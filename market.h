#ifndef MARKET_H
#define MARKET_H

#include "database.h"
#include "configurator.h"
#include <stdio.h>

class Market {
private:
	Market();
	~Market();
	static Market *p_Market;
	
	DataBase *dataBase;
	Configurator *configurator;

	int numberOfObjectTypes;

	/* Timers */
	int timer;
	int timeLeftBeforeNewSellingObject;
	int timeLeftBeforeNewObjectBought;
	void switchTimers();
	/* End of timers */

	/* Timer checkers */
	bool timeToAddSeller();
	bool timeToAddBuyer();
	bool dealPossible(int typeId);
	bool timeToPrintTimer();
	bool timeToRefreshPicture();
	bool timeToFinish();
	/* End of timer checkers */
	
	/* Statistics */
	double formSellingPrice(int type);
	double formBuyingPrice(int type);
	void resetSellingTimer();
	void resetBuyingTimer();
	
	double getNormallyDistributedValue(double mean, double standartDeviation);
	double getExponentiallyDistributedValue(double lambda);
	/* End of statistics*/

	int addSeller();
	int addBuyer();

	void printTimer();
	void refreshPicture();
public:
	static Market* getMarket();

	int tick();
	void finish();
};

#endif