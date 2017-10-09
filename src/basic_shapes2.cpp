#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "basic_shapes2");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  while (ros::ok())
  {
    visualization_msgs::Marker marker, marker2, marker3;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/robot_shape";
    marker.header.stamp = ros::Time::now();

    marker2.header.frame_id = "/robot_shape";
    marker2.header.stamp = ros::Time::now();

    marker3.header.frame_id = "/robot_shape";
    marker3.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes2";
    marker.id = 2;
    marker2.ns = "basic_shapes2";
    marker2.id = 0;
   
    marker3.ns = "basic_shapes2";
    marker3.id = 4;
    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;
    marker2.type = shape;
    marker3.type = shape;
    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;
    marker2.action = visualization_msgs::Marker::ADD;
    marker3.action = visualization_msgs::Marker::ADD;
 // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
 // marker ist nahes Objekt
 // marker2 ist mittleres Objekt
 // marker3 ist entferntestes Objekt
    marker.pose.position.x = 0;
    marker.pose.position.y = -0.2;
    marker.pose.position.z = 0.15;
    
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    
    marker2.pose.position.x = -0.5;
    marker2.pose.position.y = -0.5;
    marker2.pose.position.z = 0.15;
   
    marker2.pose.orientation.x = 0.0;
    marker2.pose.orientation.y = 0.0;
    marker2.pose.orientation.z = 0.0;
    marker2.pose.orientation.w = 1.0;

    marker3.pose.position.x = -1;
    marker3.pose.position.y = -1;
    marker3.pose.position.z = 0.15;
   
    marker3.pose.orientation.x = 0.0;
    marker3.pose.orientation.y = 0.0;
    marker3.pose.orientation.z = 0.0;
    marker3.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.03;
    marker.scale.y = 0.03;
    marker.scale.z = 0.3;

    marker2.scale.x = 0.03;
    marker2.scale.y = 0.03;
    marker2.scale.z = 0.3;

    marker3.scale.x = 0.03;
    marker3.scale.y = 0.03;
    marker3.scale.z = 0.3;
    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 1.0f;
    marker.color.g = 0.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker2.color.r = 1.0f;
    marker2.color.g = 1.0f;
    marker2.color.b = 1.0f;
    marker2.color.a = 1.0;

    marker3.color.r = 0.0f;
    marker3.color.g = 0.0f;
    marker3.color.b = 1.0f;
    marker3.color.a = 1.0;

    marker.lifetime = ros::Duration();
    marker2.lifetime = ros::Duration();
    marker3.lifetime = ros::Duration();

    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }
    marker_pub.publish(marker);
    marker_pub.publish(marker2);
    marker_pub.publish(marker3);

    r.sleep();
  }
}
