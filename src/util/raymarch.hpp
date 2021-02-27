#pragma once

#include <cmath>
#include <limits>

#include "../nodetypes/spatialnode.hpp"
#include "../nodetypes/fields/field.hpp"
#include <stereokit.h>
using namespace sk;


#define MIN_RAY_STEPS 0
#define MAX_RAY_STEPS 1000

#define MIN_RAY_MARCH 0.001f
#define MAX_RAY_MARCH std::numeric_limits<float>::max()

#define MIN_RAY_LENGTH 0.0f
#define MAX_RAY_LENGTH 1000.0f

namespace StardustXRServer {

typedef struct {
	sk::vec3 origin;
	sk::vec3 direction;
	SpatialNode *space;
} Ray;

typedef struct {
	Ray ray;
	float distance;
	sk::vec3 deepestPoint;
	sk::vec3 deepestSurfacePoint;
	float rayLength;
	int raySteps;
} RayMarchResult;

static RayMarchResult RayMarch(Ray ray, Field *field) {
	RayMarchResult result = {};
	result.ray = ray;
	result.distance = std::numeric_limits<float>::max();
	result.rayLength = 0.0f;
	result.raySteps = 0;

	sk::vec3 rayPoint = field->spaceToLocalPoint(ray.space, ray.origin);
	sk::vec3 rayDirection = field->spaceToLocalDirection(ray.space, ray.direction);

	while (result.raySteps < MAX_RAY_STEPS && result.rayLength < MAX_RAY_LENGTH) {
		float distance = field->localDistance(rayPoint);
		if(result.distance > distance)
			result.deepestPoint = rayPoint;
		result.distance = std::min(distance, result.distance);

		float marchDistance = std::clamp(distance, MIN_RAY_MARCH, MAX_RAY_MARCH);
		rayPoint += rayDirection * marchDistance;
		result.rayLength += marchDistance;
		result.raySteps++;
	}

	result.deepestSurfacePoint = field->localClosestPoint(result.deepestPoint);

	return result;
}

}
