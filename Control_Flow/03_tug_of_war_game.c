/*
    ================================================================================
    Tutorial: Control Flow - Tug of War
    ================================================================================

    This program simulates a tug of war game by summing the weights of players
    on two teams and determining which team has the higher total weight.

    Concepts Covered:
    - Using a 'for' loop to process a set number of players.
    - Accumulating totals for multiple groups within a single loop.
    - Simple 'if' statement for final comparison.
    - Handling multiple conditions with 'if-else'.
*/

#include <stdio.h>

int main(void) {
    int num_players_per_team = 0;
    int current_weight = 0;
    int team1_total_weight = 0;
    int team2_total_weight = 0;
    int winning_team = 0;

    printf("Enter the number of players on each team: ");
    scanf("%d", &num_players_per_team);

    printf("Enter the weights for each player, alternating between Team 1 and Team 2.\n");

    // This loop iterates once for each *pair* of players (one from each team).
    for (int i = 0; i < num_players_per_team; i++) {
        // Read weight for the player from Team 1
        printf("Enter weight for Team 1, player %d: ", i + 1);
        scanf("%d", &current_weight);
        team1_total_weight += current_weight;

        // Read weight for the player from Team 2
        printf("Enter weight for Team 2, player %d: ", i + 1);
        scanf("%d", &current_weight);
        team2_total_weight += current_weight;
    }

    // Determine the winner.
    // The original code defaulted the winner to Team 2. Let's make the logic
    // more explicit by checking for all three conditions: Team 1 wins, Team 2 wins, or a tie.
    if (team1_total_weight > team2_total_weight) {
        printf("Team 1 has the advantage.\n");
    } else if (team2_total_weight > team1_total_weight) {
        printf("Team 2 has the advantage.\n");
    } else {
        printf("It's a tie! The teams are perfectly matched.\n");
    }

    printf("Total weight for Team 1: %d\n", team1_total_weight);
    printf("Total weight for Team 2: %d\n", team2_total_weight);

    return 0;
}

/*
    ================================================================================
    Further Exploration:
    ================================================================================
    1.  The current input method is a bit awkward. Can you restructure the
        program to use two separate 'for' loops? The first loop would read all
        the weights for Team 1, and the second loop would read all the weights
        for Team 2. This is a more user-friendly design.
    2.  Instead of just declaring a winner, can you calculate and print by how
        much weight the winning team is ahead? (e.g., "Team 1 wins by 50 lbs").
        You might need the `abs()` function from the `<stdlib.h>` library to get
        the absolute difference.
    ================================================================================
*/
