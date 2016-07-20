#ifndef AGENT_H
#define AGENT_H

#include "object.h"
#include "configurator.h"

struct AgentInfo {
	int agentId;
	int numberOfObjects;
};

struct GeneratorMode {
	int *timerMode;

	int *priceMode;
};

struct AgentConfiguration {
	int numberOfPossiblePriceAdaptations;
	double amountOfPriceReduction;
	int timeOfPriceReduction;
	double amountOfPriceMagnification;
	int timeOfPriceMagnification;

	GeneratorMode sellers, buyers;
};

struct Status {
	int numberOfObjects;
	int numberOfObjectsGenerated;
	double averageWaitingTime;
	double averageStartPrice;
	double averagePriceAtMomentOfDeal;
};

struct AgentStatistics {
	Status forsale, bought;
};

class Agent {
protected:
	Configurator *configurator;
	int numberOfObjectTypes;

	/* Agent info */
	AgentInfo agentInfo;
	AgentConfiguration agentConfiguration;
	AgentStatistics agentStatistics;
	/* End of agent info */

	/* Timers */
	int timer;
	int *timeLeftBeforeNewSellingObject;
	int *timeLeftBeforeNewObjectBought;
	void switchTimers();
	/* End of timers */

	/* Memory */
	void allocateMemory();
	void freeMemory();
	void allocateAgentInfoMemory();
	void freeAgentInfoMemory();
	void allocateTimersMemory();
	void freeTimersMemory();
	/* End of memory */

	virtual bool readyToGenerateSeller(int type) = 0;
	virtual bool readyToGenerateBuyer(int type) = 0;
	Object getSeller();
	Object getBuyer();

	virtual double formSellingPrice(int type) = 0;
	virtual double formBuyingPrice(int type) = 0;
	virtual void resetSellingTimer(int type) = 0;
	virtual void resetBuyingTimer(int type) = 0;
	
	/* Statistics */
	double getNormallyDistributedValue(double mean, double standartDeviation);
	double getExponentiallyDistributedValue(double lambda);
	/* End of statistics*/
public:
	static int agentCounter;
	Agent();
	~Agent();
	void tick();
	Object getObject();
	void printAgentInfo();
	virtual void printAgentType() = 0;
	void handleObjectAfterDeal(Object newObject);
	void handleTimeoutObject(Object newObject);
};

class OrdinaryAgent : public Agent {
private:
	bool readyToGenerateSeller(int type);
	bool readyToGenerateBuyer(int type);
	
	double formSellingPrice(int type);
	double formBuyingPrice(int type);
	void resetSellingTimer(int type);
	void resetBuyingTimer(int type);

	void setAgentConfiguration();
public:
	void printAgentType();
	OrdinaryAgent();
};

class SoloObjectSellingAgent : public Agent {
private:
	bool readyToGenerateSeller(int type);
	bool readyToGenerateBuyer(int type);
	
	double formSellingPrice(int type);
	double formBuyingPrice(int type);
	void resetSellingTimer(int type);
	void resetBuyingTimer(int type);
	
	void setAgentConfiguration();
public:
	void printAgentType();
	SoloObjectSellingAgent();
};

#endif