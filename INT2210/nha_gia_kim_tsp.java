import random
import math

def simulated_annealing(domain, costf, temp = 10000.0,
                     cool = 0.95, step = 1):
    """simulated annealing optimization algorithm that takes a cost function and tries to minimize it by
       looking for solutions from the given domain
       requirements: is to define the costf which is needed to be minimized for error functions
       and domain which is a random solution to begin with"""
       
    # initialize the values randomly
    current_sol = [float(random.randint(domain[i][0], domain[i][1])) for i in range(len(domain))]
    while temp > 0.1:
        # choose one of the indices
        i = random.randint(0, len(domain) - 1)
        
        # choose a direction to change it
        direction = random.randint(- step, step)
        
        # create a new list with one of the values changed
        new_sol = current_sol[:]
        new_sol[i] += direction
        if new_sol[i] < domain[i][0]: new_sol[i] = domain[i][0]
        elif new_sol[i] > domain[i][1]: new_sol[i] = domain[i][1]
        
        # calculate the current cost and the new cost
        current_cost = costf(current_sol)
        new_cost = costf(new_sol)
        #p = pow(math.e, (- new_cost - current_cost) / temp)
        p = math.e ** (( - new_cost - current_cost) / temp)
        
        # is it better, or does it make the probability
        # cutoff?
        if (new_cost < current_cost or random.random() < p):
            current_sol = new_sol
            print(new_cost)
        
        # decrease the temperature
        temp = temp * cool
    return current_sol