#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "basic_shapes");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  while (ros::ok())
  {
    visualization_msgs::Marker marker, marker2;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/robot_shape";
    marker.header.stamp = ros::Time::now();

    marker2.header.frame_id = "/robot_shape";
    marker2.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "basic_shapes";
    marker.id = 0;
    marker2.ns = "basic_shapes";
    marker2.id = 2;
    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;
marker2.type = shape;

    // Set the marker action.  Options are ADD, DELETE, and new in ROS Indigo: 3 (DELETEALL)
    marker.action = visualization_msgs::Marker::ADD;
    marker2.action = visualization_msgs::Marker::ADD;
   
 // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
 // marker ist Roboter
 //marker2 ist Sicherheitszone
    marker.pose.position.x = 0;
    marker.pose.position.y = 0;
    marker.pose.position.z = 0.125;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    
    marker2.pose.position.x = 0;
    marker2.pose.position.y = 0;
    marker2.pose.position.z = 0;
    marker2.pose.orientation.x = 0.0;
    marker2.pose.orientation.y = 0.0;
    marker2.pose.orientation.z = 0.0;
    marker2.pose.orientation.w = 1.0;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.4;
    marker.scale.y = 0.8;
    marker.scale.z = 0.25;

    marker2.scale.x = 0.9;
    marker2.scale.y = 1.3;
    marker2.scale.z = 0;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 1.0f;
    marker.color.g = 0.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0;

    marker2.color.r = 1.0f;
    marker2.color.g = 1.0f;
    marker2.color.b = 1.0f;
    marker2.color.a = 1.0;

    marker.lifetime = ros::Duration();
marker2.lifetime = ros::Duration();

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


    r.sleep();
  }
}
