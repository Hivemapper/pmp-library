// Copyright 2017-2021 the Polygon Mesh Processing Library developers.
// Distributed under a MIT-style license, see LICENSE.txt for details.

#include "gtest/gtest.h"

#include <pmp/algorithms/SurfaceFactory.h>

using namespace pmp;

bool vertices_on_sphere(const SurfaceMesh& mesh)
{
    for (auto v : mesh.vertices())
    {
        const Scalar n = norm(mesh.position(v));
        if (n < 0.999 || n > 1.001)
        {
            return false;
        }
    }
    return true;
}

TEST(SurfaceFactoryTest, tetrahedron)
{
    auto mesh = SurfaceFactory::tetrahedron();
    EXPECT_EQ(mesh.n_vertices(), 4u);
    EXPECT_EQ(mesh.n_edges(), 6u);
    EXPECT_EQ(mesh.n_faces(), 4u);
    EXPECT_TRUE(mesh.is_triangle_mesh());
    EXPECT_TRUE(vertices_on_sphere(mesh));
}

TEST(SurfaceFactoryTest, octahedron)
{
    auto mesh = SurfaceFactory::octahedron();
    EXPECT_EQ(mesh.n_vertices(), 6u);
    EXPECT_EQ(mesh.n_edges(), 12u);
    EXPECT_EQ(mesh.n_faces(), 8u);
    EXPECT_TRUE(mesh.is_triangle_mesh());
    EXPECT_TRUE(vertices_on_sphere(mesh));
}

TEST(SurfaceFactoryTest, hexahedron)
{
    auto mesh = SurfaceFactory::hexahedron();
    EXPECT_EQ(mesh.n_vertices(), 8u);
    EXPECT_EQ(mesh.n_edges(), 12u);
    EXPECT_EQ(mesh.n_faces(), 6u);
    EXPECT_TRUE(mesh.is_quad_mesh());
    EXPECT_TRUE(vertices_on_sphere(mesh));
}

TEST(SurfaceFactoryTest, icosahedron)
{
    auto mesh = SurfaceFactory::icosahedron();
    EXPECT_EQ(mesh.n_vertices(), 12u);
    EXPECT_EQ(mesh.n_edges(), 30u);
    EXPECT_EQ(mesh.n_faces(), 20u);
    EXPECT_TRUE(mesh.is_triangle_mesh());
    EXPECT_TRUE(vertices_on_sphere(mesh));
}

TEST(SurfaceFactoryTest, dodecahedron)
{
    auto mesh = SurfaceFactory::dodecahedron();
    EXPECT_EQ(mesh.n_vertices(), 20u);
    EXPECT_EQ(mesh.n_edges(), 30u);
    EXPECT_EQ(mesh.n_faces(), 12u);
    EXPECT_FALSE(mesh.is_triangle_mesh());
    EXPECT_FALSE(mesh.is_quad_mesh());
    EXPECT_TRUE(vertices_on_sphere(mesh));
}

TEST(SurfaceFactoryTest, icosphere)
{
    auto mesh = SurfaceFactory::icosphere();
    EXPECT_EQ(mesh.n_vertices(), 642u);
    EXPECT_EQ(mesh.n_edges(), 1920u);
    EXPECT_EQ(mesh.n_faces(), 1280u);
    EXPECT_TRUE(mesh.is_triangle_mesh());
    EXPECT_TRUE(vertices_on_sphere(mesh));
}

TEST(SurfaceFactoryTest, quad_sphere)
{
    auto mesh = SurfaceFactory::quad_sphere();
    EXPECT_EQ(mesh.n_vertices(), 386u);
    EXPECT_EQ(mesh.n_edges(), 768u);
    EXPECT_EQ(mesh.n_faces(), 384u);
    EXPECT_TRUE(mesh.is_quad_mesh());
    EXPECT_TRUE(vertices_on_sphere(mesh));
}

TEST(SurfaceFactoryTest, uv_sphere)
{
    auto mesh = SurfaceFactory::uv_sphere();
    EXPECT_EQ(mesh.n_vertices(), 212u);
    EXPECT_EQ(mesh.n_edges(), 435u);
    EXPECT_EQ(mesh.n_faces(), 225u);
    EXPECT_FALSE(mesh.is_triangle_mesh());
    EXPECT_FALSE(mesh.is_quad_mesh());
    EXPECT_TRUE(vertices_on_sphere(mesh));
}
