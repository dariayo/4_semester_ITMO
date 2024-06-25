import random

distances = [
    [0, 1, 7, 2, 8],
    [2, 0, 10, 3, 1],
    [7, 10, 0, 2, 6],
    [2, 3, 2, 0, 4],
    [8, 1, 6, 4, 0]
]
population = []

def distances_count(population):
    distance = 0
    for i in range(len(population) - 1):
        distance += distances[population[i] - 1][population[i + 1] - 1]
    distance += distances[population[-1] - 1][population[0] - 1]
    return distance

def generate_population():
    for _ in range(5):
        genome = list(range(1, 5 + 1))
        random.shuffle(genome)
        population.append(genome)
    return population

def mutate(child, start, end):
    if random.random() < 0.01:
        child[start:end + 1] = random.sample(child[start:end + 1], len(child[start:end + 1]))

def crossover(parent1, parent2):
    start, end = sorted(random.sample(range(len(parent1)), 2))
    child1 = [None] * len(parent1)
    child2 = [None] * len(parent2)
    child1[start:end + 1] = parent2[start:end + 1]
    child2[start:end + 1] = parent1[start:end + 1]
    s = start + 1
    for i in range(len(parent1)):
        if not (parent1[s] in child1):
            child1[child1.index(None)] = parent1[s]
        if not (parent2[s] in child2):
            child2[child2.index(None)] = parent2[s]
        if s == len(parent1) - 1:
            s = -1
        s += 1
    mutate(child1, start, end)
    mutate(child2, start, end)
    new_population = []
    new_population.append(child1 if distances_count(child1) < distances_count(parent1) else parent1)
    new_population.append(child2 if distances_count(child2) < distances_count(parent2) else parent2)
    print(distances_count(child1), distances_count(child2))

    return new_population

if __name__ == '__main__':
    generate_population()
    child1 = crossover(population[0], population[1])
    child2 = crossover(population[2], population[3])
    for i in range(1000):
        child1 = crossover(child1[0], child1[1])
        child2 = crossover(child2[0], child2[1])
    min = child1[0] if distances_count(child1[0]) < distances_count(child1[1]) else child1[1]
    min_two = child2[0] if distances_count(child2[0]) < distances_count(child2[1]) else child2[1]
    print(min if distances_count(min) < distances_count(min_two) else min_two)
    print(distances_count(min) if distances_count(min) < distances_count(min_two) else distances_count(min_two))
