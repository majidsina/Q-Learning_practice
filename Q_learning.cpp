#include <iostream>
#include <fstream>
#include "Environment.h"
#include "Agent.h"
#include "Q_learning.h"
using namespace std;

Q_learning::Q_learning(Agent& ao, Environment& eo, int num_episodes)
// member initializer list
:	agent_object(ao),
	environment_object(eo),
	number_of_episodes(num_episodes){

	// construct the policy
	reward_per_episode = new int [num_episodes];
}

	
void Q_learning::learn(){

	// initialize the state, action, reward and final episode
	int s, a, r, episode_end;
	int total_reward = 0;

	// loop over all episodes
	for (int i = 0; i < number_of_episodes; i++){
		// reset the environment at the start of every episode
		environment_object.ResetEnvironment();
		total_reward = 0;

		// get the current state, which is equal agents initialization location
		s = environment_object.GetStateIndex();

		// pass the state to the agent
		agent_object.SetStateIndex(s);

		// while the episode is not finished/agent is not at the goal state
		do{
			// select and retrieve the agents action for the current state
			agent_object.SelectAction();
			a = agent_object.GetActionIndex();

			// apply the action to the environment, observe new state and reward
			environment_object.ApplyAction(a);
			r = environment_object.GetReward();
			s = environment_object.GetStateIndex();
			total_reward = total_reward + r;

			// update the Q_table with the new state and the reward
			agent_object.UpdateQTable(s, r);
			
			// set the new state as the current state
			agent_object.SetStateIndex(s);

			// check if the episode is comlpete
			episode_end = environment_object.GetEpisodeEnd();

		}while(episode_end != 1);

		// update the policy after every episode
		agent_object.UpdatePolicy();

		// save the reward per episode
		reward_per_episode[i] = total_reward;
	}

	// save the reward_per_episode
	save_reward_per_episode();	
}

// save_reward_per_episode function
void Q_learning::save_reward_per_episode(){

	// open the file stream
	ofstream output_file("reward_per_episode.txt");

	for(int i = 0; i < number_of_episodes; i++){

		output_file << i + 1 << " " << reward_per_episode[i] << endl;
	}
}


Q_learning::~Q_learning(){

}
