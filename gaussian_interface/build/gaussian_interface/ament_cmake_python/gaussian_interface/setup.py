from setuptools import find_packages
from setuptools import setup

setup(
    name='gaussian_interface',
    version='0.0.1',
    packages=find_packages(
        include=('gaussian_interface', 'gaussian_interface.*')),
)
