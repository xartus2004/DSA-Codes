            cout << parent[i] << " - " << i << "\t"<<"-> "<< graph[i][parent[i]] << " \n";
            minCost+=graph[i][parent[i]];
