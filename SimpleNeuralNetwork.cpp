/*
 * SimpleNeuralNetwork
 *
 * Example implementation of a simple neural network
 *
 * By Anders Bennehag
 */


#include <iostream>
#include <cstdlib>
#include <ctime>


#include "SimpleNeuralNetwork.h"





SimpleNeuralNetwork::SimpleNeuralNetwork( int inputNeurons, int neuronsPerHiddenLayer, int hiddenLayers )
{
	// Todo: remove:
	srand( time(0) );

	// Set up network
	std::vector<Neuron> inputLayer;
	inputLayer.resize(inputNeurons);
	neurons.push_back( inputLayer );

	for (int i=1; i <= hiddenLayers+1; ++i)
	{
		std::vector<Neuron> newLayer;
		if (i == hiddenLayers+1)
			newLayer.resize(1); // This is the last layer. Use 1 output neuron
		else
			newLayer.resize(neuronsPerHiddenLayer);

		// Add connections
		for (int neuron=0; neuron<newLayer.size(); ++neuron)
		{
			std::vector<neuronType> conn;
			conn.resize(neurons[i-1].size());
			for (int w=0; w < conn.size(); ++w)
				conn[w] = rand()%100/100.0;
			newLayer[neuron].connections = conn;
		}

		neurons.push_back( newLayer );
	}

}


neuronType SimpleNeuralNetwork::calculateOutput( std::vector<neuronType> input )
{
	if (input.size() != neurons[0].size() )
	{
		std::cout << "Input dimensions differs from number of input neurons\n";
		return 0;
	}

	for (int layer=0; layer < neurons.size(); ++layer)
	{
		//std::cout << "Entering layer "<<layer<<std::endl;
		for (int i=0; i < neurons[layer].size(); ++i)
		{
			Neuron* neuron = &neurons[layer][i];
			//std::cout << "Entering neurons loop. Neuron has "<<neuron->connections.size()<<" connections\n";
			for (int weight=0; weight < neuron->connections.size(); weight++ )
			{
				//std::cout << "Entering connections loop\n";
				float incomingValue=0;
				if (weight==0)
					incomingValue = input[weight]; // Use input data
				else
					incomingValue = neurons[layer-1][weight].value; // Use previous layer

				neuron->value += neuron->connections[weight] * incomingValue;

				//std::cout << "Value "<<incomingValue<<" multiplied with weight "<<neuron->connections[weight]<<std::endl;
			}
		}
	}

	return neurons.back()[0].value;
}

SimpleNeuralNetwork::~SimpleNeuralNetwork()
{

}
