// PCLDataViewer.cpp : Defines the entry point for the application.
//

#include "PCLDataViewer.h"

#include <pcl/visualization/cloud_viewer.h>
#include <pcl/io/io.h>
#include <pcl/io/pcd_io.h>

#include <boost/algorithm/string.hpp>

using namespace std;
void Import(std::string importpath, pcl::PointCloud<pcl::PointXYZRGBA>& cloud, std::vector<std::vector<pcl::PointXYZRGBA>>& mapper) {
    
    ifstream ifs(importpath);
    if (!ifs) {
        return;
    }

    string line;
    bool detectmarking = false;
    while (!detectmarking && std::getline(ifs, line) ) {
        if (line.find("#####") != string::npos) {
            detectmarking = true;
            continue;
        }
    }

    detectmarking = false;
    std::map<int, pcl::PointXYZRGBA> element_list;
    while (!detectmarking && std::getline(ifs, line) ) {
        if (line.find("#####") != string::npos) {
            detectmarking = true;
            continue;
        }

        list<string> line_string;
        string delim(",");
        boost::split(line_string, line, boost::is_any_of(delim));

        if (line_string.size() >= 4) {
            std::list<std::string>::iterator iter = line_string.begin();
            string name = *iter;

            pcl::PointXYZRGBA point;
            std::advance(iter, 1);
            point.x = std::atof(iter->c_str());
            std::advance(iter, 1);
            point.y = std::atof(iter->c_str());
            std::advance(iter, 1);
            point.z = std::atof(iter->c_str());
            point.r = 255;
            point.g = point.b = point.a = 0;

            element_list[std::atoi(name.c_str())] = point;
        }
    }

    detectmarking = false;
    mapper.resize(2*element_list.size());
    while (!detectmarking && std::getline(ifs, line) ) {
        if (line.find("#####") != string::npos) {
            detectmarking = true;
            continue;
        }

        list<string> line_string;
        string delim(",");
        boost::split(line_string, line, boost::is_any_of(delim));

        if (line_string.size() >= 2) {
            std::list<std::string>::iterator iter = line_string.begin();
            int definedno = std::atoi(iter->c_str());
            mapper[definedno].push_back(element_list[definedno]);

            std::advance(iter, 2);
            for (; iter != line_string.end(); iter++) {
                if (*iter != "" ) {
                    mapper[definedno].push_back(element_list[std::atoi(iter->c_str())]);
                }
            }
        }
    }

    ifs.close();



    for (auto element = element_list.begin(); element != element_list.end(); element++) {
        cloud.push_back(element->second);
    }


}

void viewerOneOff(pcl::visualization::PCLVisualizer& viewer)
{
    pcl::PointCloud<pcl::PointXYZRGBA>::Ptr cloud(new pcl::PointCloud<pcl::PointXYZRGBA>);
    std::vector<std::vector<pcl::PointXYZRGBA>> mapper;
    Import("curve_edge.csv", *cloud, mapper);

    viewer.addPointCloud<pcl::PointXYZRGBA>(cloud, "cloud");
    viewer.setPointCloudRenderingProperties( pcl::visualization::PCL_VISUALIZER_POINT_SIZE, 4, "cloud");

    int ind = 0;
    for (auto iter = mapper.begin(); iter != mapper.end(); iter++) {
        if (iter->size() == 0) {
            continue;
        }

        pcl::PointXYZRGBA p1 = (*iter)[0];
        for (int i = 1; i < iter->size(); i++) {
            pcl::PointXYZRGBA p2 = (*iter)[i];

            stringstream ss;
            ss << "Line" << ind++;

            viewer.addLine(p1, p2, 0, 0, 255, ss.str());
        }
    }


    // base
    pcl::PointXYZ basexm, basexp;
    basexm.x = -28, basexp.x = 28;
    basexm.y = basexp.y = 0;
    basexm.z = basexp.z = 2.5;
    viewer.addLine(basexm, basexp, "BaseX");
    pcl::PointXYZ baseym, baseyp;
    baseym.y = -28, baseyp.y = 28;
    baseym.x = baseyp.x = 0;
    baseym.z = baseyp.z = 2.5;
    viewer.addLine(baseym, baseyp, "BaseY");


    double R0 = 36.5;
    double theta = 60 * M_PI / 180;
    double X0 = 45;
    double Y0 = 40;


    auto rotate_point = [](double phase, pcl::PointXYZ org) {
        pcl::PointXYZ res;
        res.x = cos(phase) * org.x - sin(phase) * org.y;
        res.y = sin(phase) * org.x + cos(phase) * org.y;
        res.z = org.z;

        return res;
    };



    int cnt = 0;
    for (double phase = 0; phase < 2 * M_PI; phase += 2 * M_PI) {
        stringstream ss_pz0;
        stringstream ss_pzz;

        ss_pz0 << "pz0" << cnt;
        ss_pzz << "pzz" << cnt++;

        pcl::PointXYZ p1_z0;
        p1_z0.x = X0 + (-1 - R0) * cos(theta);
        p1_z0.y = Y0 + (-1 - R0) * sin(theta);
        p1_z0.z = 2.6;
        pcl::PointXYZ p2_z0;
        p2_z0.x = X0 + (5 - R0) * cos(theta);
        p2_z0.y = Y0 + (5 - R0) * sin(theta);
        p2_z0.z = 2.6;
        pcl::PointXYZ p1_zz;
        p1_zz.x = p1_z0.x;
        p1_zz.y = p1_z0.y;
        p1_zz.z = 2.4;
        pcl::PointXYZ p2_zz;
        p2_zz.x = p2_z0.x;
        p2_zz.y = p2_z0.y;
        p2_zz.z = 2.4;


        pcl::PointXYZ p1_z0_rot = rotate_point(phase, p1_z0);
        pcl::PointXYZ p2_z0_rot = rotate_point(phase, p2_z0);
        pcl::PointXYZ p1_zz_rot = rotate_point(phase, p1_zz);
        pcl::PointXYZ p2_zz_rot = rotate_point(phase, p2_zz);


        viewer.addLine(p1_z0_rot, p2_z0_rot, 0, 255, 0, ss_pz0.str());
        viewer.addLine(p1_zz_rot, p2_zz_rot, 0, 255, 0, ss_pzz.str());
    }

    pcl::ModelCoefficients circlecoef;
    circlecoef.values.push_back(0);
    circlecoef.values.push_back(0);
    circlecoef.values.push_back(0);

    circlecoef.values.push_back(0);
    circlecoef.values.push_back(0);
    circlecoef.values.push_back(1);

    circlecoef.values.push_back(28);
    viewer.addCylinder(circlecoef);

    
}


int main(int argv, char** argc)
{
    pcl::visualization::CloudViewer viewer("Cloud Viewer");



    viewer.runOnVisualizationThreadOnce(viewerOneOff);
    while (!viewer.wasStopped())
    {
        
    }


	return 0;
}
