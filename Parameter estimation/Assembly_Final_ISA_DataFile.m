% Simscape(TM) Multibody(TM) version: 7.7

% This is a model data file derived from a Simscape Multibody Import XML file using the smimport function.
% The data in this file sets the block parameter values in an imported Simscape Multibody model.
% For more information on this file, see the smimport function help page in the Simscape Multibody documentation.
% You can modify numerical values, but avoid any other changes to this file.
% Do not add code to this file. Do not edit the physical units shown in comments.

%%%VariableName:smiData


%============= RigidTransform =============%

%Initialize the RigidTransform structure array by filling in null values.
smiData.RigidTransform(10).translation = [0.0 0.0 0.0];
smiData.RigidTransform(10).angle = 0.0;
smiData.RigidTransform(10).axis = [0.0 0.0 0.0];
smiData.RigidTransform(10).ID = "";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(1).translation = [0 0 67.650000000000006];  % mm
smiData.RigidTransform(1).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(1).axis = [1 0 0];
smiData.RigidTransform(1).ID = "B[Motor-1:-:encoderBracketInventor.stp-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(2).translation = [-17.499999999999968 -4.9999999999999929 -3.5527136788005009e-15];  % mm
smiData.RigidTransform(2).angle = 2.0943951023931948;  % rad
smiData.RigidTransform(2).axis = [0.57735026918962551 -0.57735026918962629 0.57735026918962551];
smiData.RigidTransform(2).ID = "F[Motor-1:-:encoderBracketInventor.stp-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(3).translation = [0 0 35];  % mm
smiData.RigidTransform(3).angle = 0;  % rad
smiData.RigidTransform(3).axis = [0 0 0];
smiData.RigidTransform(3).ID = "B[Encoder-1:-:encoderBracketInventor.stp-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(4).translation = [-29.999999999999986 29.999999999999975 1.0658141036401503e-14];  % mm
smiData.RigidTransform(4).angle = 1.5707963267948966;  % rad
smiData.RigidTransform(4).axis = [-1.3779359818826495e-16 -1 1.3779359818826453e-16];
smiData.RigidTransform(4).ID = "F[Encoder-1:-:encoderBracketInventor.stp-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(5).translation = [0 0 0];  % mm
smiData.RigidTransform(5).angle = 0;  % rad
smiData.RigidTransform(5).axis = [0 0 0];
smiData.RigidTransform(5).ID = "B[Rigid 6 to 8mm Coupler v2.step-2:-:8mm Allen Key-3]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(6).translation = [-127.00000000000003 0 -30.999999999999982];  % mm
smiData.RigidTransform(6).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(6).axis = [0.15089164300285712 -0.98855030831612134 1.653340887320839e-16];
smiData.RigidTransform(6).ID = "F[Rigid 6 to 8mm Coupler v2.step-2:-:8mm Allen Key-3]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(7).translation = [0 0 40];  % mm
smiData.RigidTransform(7).angle = 0;  % rad
smiData.RigidTransform(7).axis = [0 0 0];
smiData.RigidTransform(7).ID = "B[Encoder-1:-:Rigid 6 to 8mm Coupler v2.step-2]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(8).translation = [-6.0898016340275317e-14 -6.8542477776686124e-15 23.999999999999986];  % mm
smiData.RigidTransform(8).angle = 3.1415926535897931;  % rad
smiData.RigidTransform(8).axis = [-1 -8.2535586367037034e-34 1.6052891425780511e-17];
smiData.RigidTransform(8).ID = "F[Encoder-1:-:Rigid 6 to 8mm Coupler v2.step-2]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(9).translation = [0 0 0];  % mm
smiData.RigidTransform(9).angle = 0;  % rad
smiData.RigidTransform(9).axis = [0 0 0];
smiData.RigidTransform(9).ID = "AssemblyGround[Rigid 6 to 8mm Coupler v2.step-2:Coupler.step-1]";

%Translation Method - Cartesian
%Rotation Method - Arbitrary Axis
smiData.RigidTransform(10).translation = [23.817057157946063 13.649383094465801 60.717804228064296];  % mm
smiData.RigidTransform(10).angle = 1.5707963267948861;  % rad
smiData.RigidTransform(10).axis = [-1 0 0];
smiData.RigidTransform(10).ID = "RootGround[Motor-1]";


%============= Solid =============%
%Center of Mass (CoM) %Moments of Inertia (MoI) %Product of Inertia (PoI)

%Initialize the Solid structure array by filling in null values.
smiData.Solid(5).mass = 0.0;
smiData.Solid(5).CoM = [0.0 0.0 0.0];
smiData.Solid(5).MoI = [0.0 0.0 0.0];
smiData.Solid(5).PoI = [0.0 0.0 0.0];
smiData.Solid(5).color = [0.0 0.0 0.0];
smiData.Solid(5).opacity = 0.0;
smiData.Solid(5).ID = "";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(1).mass = 0.015204885399045846;  % kg
smiData.Solid(1).CoM = [-0.0025162948581534815 0.077768686867538156 33.458504349221258];  % mm
smiData.Solid(1).MoI = [5.4573877921419651 5.449672974289407 1.2191584020137589];  % kg*mm^2
smiData.Solid(1).PoI = [0.044005723408034464 -0.00031303172538450438 0.00020940321768877427];  % kg*mm^2
smiData.Solid(1).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(1).opacity = 1;
smiData.Solid(1).ID = "Motor*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(2).mass = 0.041460111613469644;  % kg
smiData.Solid(2).CoM = [-0.12171654944629376 -0.00038653739303960689 18.410754180309596];  % mm
smiData.Solid(2).MoI = [8.4665258871855436 8.5864579163144477 7.2762789739356339];  % kg*mm^2
smiData.Solid(2).PoI = [0.0010915340293272987 -0.042056486216784039 6.5021219071039487e-06];  % kg*mm^2
smiData.Solid(2).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(2).opacity = 1;
smiData.Solid(2).ID = "Encoder*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(3).mass = 0.015051323807251533;  % kg
smiData.Solid(3).CoM = [-22.994563477946549 8.2725166695066026 -7.3679060299944211e-07];  % mm
smiData.Solid(3).MoI = [4.6132494114588853 3.0828656793593328 4.5653830939933862];  % kg*mm^2
smiData.Solid(3).PoI = [-1.3512043147648042e-07 1.5011460151872599e-07 1.2128046914619008];  % kg*mm^2
smiData.Solid(3).color = [0.74901960784313726 0.74901960784313726 0.74901960784313726];
smiData.Solid(3).opacity = 1;
smiData.Solid(3).ID = "encoderBracketInventor.stp*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(4).mass = 0.0034003794114547807;  % kg
smiData.Solid(4).CoM = [0.13062192187788335 -0.15441725077396165 11.360839598050942];  % mm
smiData.Solid(4).MoI = [0.20271890785683708 0.2028928377886681 0.13010786840116037];  % kg*mm^2
smiData.Solid(4).PoI = [6.5768357126547745e-06 -2.4136108206659247e-05 -0.00051849331783532162];  % kg*mm^2
smiData.Solid(4).color = [0.792156862745098 0.81960784313725488 0.93333333333333335];
smiData.Solid(4).opacity = 1;
smiData.Solid(4).ID = "Coupler.step*:*Default";

%Inertia Type - Custom
%Visual Properties - Simple
smiData.Solid(5).mass = 0.0088410961948555897;  % kg
smiData.Solid(5).CoM = [-72.301648655303708 -0.00022976899737462444 -3.8531976077846561];  % mm
smiData.Solid(5).MoI = [0.75151151487558876 18.054783955937449 17.377111408321134];  % kg*mm^2
smiData.Solid(5).PoI = [1.1629059805747702e-05 -1.8623315618370284 3.6423328588214567e-05];  % kg*mm^2
smiData.Solid(5).color = [0.89803921568627454 0.89803921568627454 0.89803921568627454];
smiData.Solid(5).opacity = 1;
smiData.Solid(5).ID = "8mm Allen Key*:*Default";


%============= Joint =============%
%X Revolute Primitive (Rx) %Y Revolute Primitive (Ry) %Z Revolute Primitive (Rz)
%X Prismatic Primitive (Px) %Y Prismatic Primitive (Py) %Z Prismatic Primitive (Pz) %Spherical Primitive (S)
%Constant Velocity Primitive (CV) %Lead Screw Primitive (LS)
%Position Target (Pos)

%Initialize the RevoluteJoint structure array by filling in null values.
smiData.RevoluteJoint(2).Rz.Pos = 0.0;
smiData.RevoluteJoint(2).ID = "";

smiData.RevoluteJoint(1).Rz.Pos = 179.99999999999997;  % deg
smiData.RevoluteJoint(1).ID = "[Motor-1:-:encoderBracketInventor.stp-1]";

smiData.RevoluteJoint(2).Rz.Pos = 107.35720419846854;  % deg
%smiData.RevoluteJoint(2).Rz.Pos = 0;  % deg
smiData.RevoluteJoint(2).ID = "[Encoder-1:-:Rigid 6 to 8mm Coupler v2.step-2]";

