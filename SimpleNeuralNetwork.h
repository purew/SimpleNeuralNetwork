/*
 * SimpleNeuralNetwork
 *
 * Example implementation of a simple neural network
 *
 * By Anders Bennehag
 */

#ifndef SIMPLENEURALNETWORK_H_
#define SIMPLENEURALNETWORK_H_

#include <vector>

typedef float neuronType;

struct Neuron
{
	std::vector<neuronType> connections;
	neuronType value;
};


class SimpleNeuralNetwork
{
public:
	SimpleNeuralNetwork( int inputNeurons, int neuronsPerHiddenLayer, int hiddenLayers );
	~SimpleNeuralNetwork();

	/** For given input, calculate the output. */
	neuronType calculateOutput( std::vector<neuronType> input );

private:

	std::vector< std::vector<Neuron> > neurons;
};





#endif
