#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Environment.h"
#include "Agent.h"
#include "Q_learning.h"
using namespace std;


int main(){
	// pick the seed location
	srand(time(0));

	// -------------------------------
	// ------Environment settings-----
	// -------------------------------
	// initialize and construct
	int grid_width = 25;
	int grid_height = 25;

	Environment environment_object(grid_width, grid_height);
	
	// agent start grid position
	int agent_start_x_grid_position = 0; 
	int agent_start_y_grid_position = 0;

	// goal grid position
	int goal_x_grid_position = 24;
	int goal_y_grid_position = 24;

	// set the positions
	environment_object.SetAgentStartGridPosition(agent_start_x_grid_position, agent_start_y_grid_position);
	environment_object.SetGoalGridPosition(goal_x_grid_position, goal_y_grid_position);

	// -------------------------
	// ------Agent settings-----
	// -------------------------
	// initialize and construct
	int number_of_states = grid_width*grid_height;
	int number_of_actions = 4;

	Agent agent_object(number_of_states, number_of_actions);

	// declare other variables
	double alpha = 0.3, gamma = 0.8, epsilon = 1;

	// set other variables; 
	agent_object.SetAlpha(alpha);
	agent_object.SetGamma(gamma);
	agent_object.SetEpsilon(epsilon);

	// -----------------------------
	// ------Q-learning routine-----
	// -----------------------------
	// specify number of episodes
	int number_of_episodes = 1000;

	// initialize the Q_learing object
	Q_learning Q_object(agent_object, environment_object, number_of_episodes);
	
	// learn
	Q_object.Learn();

	// plot
	Q_object.PlotRewardPerEpisode();

	// print out results
    // agent_object.PrintQTable();
    // agent_object.PrintPolicy();
    // agent_object.PrintMaxQValuePerState(grid_width, grid_height);
}