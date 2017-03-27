#ifndef Q_LEARNING_H
#define Q_LEARNING_H

class Q_learning
{
public:
	// constructor
	Q_learning(Agent& agent_object, Environment& environment_object, int number_of_episodes);

	// public function
	void learn();

	// deconstructor
	~Q_learning();

private:
	// class variables
	int number_of_episodes;

	// agent and environment
	Agent& agent_object;
	Environment& environment_object;
	
	// arrays
	int* reward_per_episode;

	// private functions
	void save_reward_per_episode();
};

#endif