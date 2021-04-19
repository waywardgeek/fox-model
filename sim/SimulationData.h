#include <vector>
#include "fox_model/FoxLibrary.h"
#include "DiseaseData.h"
#include "PopulationData.h"

#ifndef SUMMARY
#define SUMMARY

// Class that stores the data to be analyzed from each simulation.
class SimulationData
{
public:
    void updatePopSummary(PopulationData &pop);
	void updateDiseaseSummary(DiseaseData stateAtTimestep);
    void storeSeedFox(Fox f);
    SimulationData(int simNum, int popSize, int timestep);
    void printStuff();
    std::vector<DiseaseData>* getDiseaseMatrix() { return &diseaseMatrix; }
    PopulationData* getPopData() { return pop; }
    int getSimNumber() { return simNumber; }
    int getTimestepNumber() { return timestepNumber; }
    int getN() { return N; }


private:
	int simNumber;
	int N;
	int timestepNumber;
	std::vector <DiseaseData> diseaseMatrix;
	PopulationData* pop; //We may run several simulations for one initial population, so ptr use saves memory.
    Fox seedFox;
};
#endif
