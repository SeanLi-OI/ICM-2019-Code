#include "solve.h"
int Solve::floor_check(string name, int floor_id)
{
    string name_tmp = name + floor_name[floor_id];
    auto it = id.find(name_tmp);
    if (it == id.end())
        return -1;
    else
        return it->second;
}
int Solve::id_find(string name, int floor_id)
{
    string name_tmp = name;
    if (name[0] == 'S')
        name_tmp = name + floor_name[floor_id];
    auto it = id.find(name_tmp);
    if (it == id.end())
    {
        int _id = mapcore.add_node(name), __id;
        id[name_tmp] = _id;
        if (name[0] == 'S')
        {
            __id = floor_check(name, floor_id - 1);
            if (__id != -1)
                mapcore.add_edge(__id, _id, C4, C5);
            __id = floor_check(name, floor_id + 1);
            if (__id != -1)
                mapcore.add_edge(__id, _id, C4, C5);
        }
        if (name[0] == 'E')
        {
            mapcore.add_edge(_id, mapcore.end_node, C0, 0);
        }
        return _id;
    }
    else
        return it->second;
}
void Solve::init()
{
    id.clear();
    mapcore.init();
}
void Solve::input()
{
    int floor_num, room_num, path_num;
    int id1, id2;
    string name, name1, name2;
    double area, length;
    scanf("%d", &floor_num);
    for (int i = 1; i <= floor_num; i++)
    {
        scanf("%d", &room_num);
        for (int j = 1; j <= room_num; j++)
        {
            cin >> name >> area;
            id1 = mapcore.add_node(name);
            id2 = mapcore.add_node(name);
            mapcore.add_edge(mapcore.start_node, id1, C0, 0);
            mapcore.add_edge(id1, id2, area * C2, area / C1);
            if (id.find(name) != id.end())
            {
                cout << "ERROR: Room " << name << " repeats. Please check you data.in again." << endl;
                exit(0);
            }
            id[name] = id2;
        }
        scanf("%d", &path_num);
        for (int j = 1; j <= path_num; j++)
        {
            cin >> name1 >> name2 >> length;
            id1 = id_find(name1, i);
            id2 = id_find(name2, i);
            mapcore.add_edge(id1, id2, length * C3, length * C4);
        }
    }
}
void Solve::solve()
{
    mapcore.maxflow();
}